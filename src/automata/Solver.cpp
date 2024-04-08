#include "Solver.h"
#include "ThreadPool.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include <latch>
#include <semaphore>

Solver::Solver(std::vector<Entity>* ents,  int width,  int height, float _time_step) {
    m_width = width;
    m_height = height;
    m_entities = ents;
    time_step = _time_step;
}

Solver::~Solver() {
}

void Solver::update() {
    int pool_size = ThreadPool::getInstance().getPoolSize();

    int chunk_size = std::ceil(m_height / (float) pool_size);
    int num_evens = pool_size;

    int offset = rand() % (chunk_size / 3) - chunk_size / 4;

    // printf("Active Threads 1: %d\n", ThreadPool::getInstance().getQueueSize());
    int i = 0;
    {
        std::counting_semaphore semaphore(0);
        int start = 0;
        int end = 0;
        for (i = 0; i < pool_size && start < m_height - 1; i++) {
            end = start + chunk_size;
            int mid = start + chunk_size / 2;
            if (i == 0) end += offset;
            mid = std::min(mid, m_height);
            // printf("Rows 1: %d, %d, %d\n", start, mid, end);
            ThreadPool::getInstance().enqueue([this, start, mid, &semaphore] {
                update(start, mid);
                semaphore.release();
                });
            start = end;
        }

        for (int j = 0; j < i; j++) {
            semaphore.acquire();
        }
    }

    // printf("Active Threads 2: %d\n", ThreadPool::getInstance().getQueueSize());
    {
        std::counting_semaphore semaphore(0);

        int start = 0;
        int end = 0;
        for (i = 0; i < pool_size && start < m_height - 1; i++) {
            end = start + chunk_size;
            int mid = start + chunk_size / 2;
            if (i == 0) end += offset;
            end = std::min(end, m_height);
            // printf("Rows 2: %d, %d,m %d\n", start, mid, end);
            ThreadPool::getInstance().enqueue([this, mid , end, &semaphore] {
                update(mid, end);
                semaphore.release();
            });
            start = end;
        }

        for (int j = 0; j < i; j++) {
            semaphore.acquire();
        }
    }
}

void Solver::update(int row_begin, int row_end) {
    for (int row = row_begin; row < row_end; row++) {
        for (int col = 0; col < m_width; col++) {
            Entity &ent = getEntity(row, col);
            if (ent.type == EntityType::EMPTY) continue;

            ent.acceleration = {0, 0};

            if (ent.is_moveable) {
                ent.is_updated = false;
            }
        }
    }

    for (int row = row_begin; row < row_end; row++) {
        for (int col = 0; col < m_width; col++) {
            Entity &ent = getEntity(row, col);
            if (ent.type == EntityType::EMPTY || ent.is_updated) continue;

            ent.is_updated = true;
            ent.acceleration = {0, 0};

            if (ent.is_moveable && ent.is_active) {
                // printf("Velocity (%f, %f)\n", ent.velocity.x, ent.velocity.y);
                applyGravity(row, col, -5);
                applyFriction(row, col);

                if (std::abs(ent.velocity.x) < EPSILON )
                    ent.velocity.x = 0;
                if (std::abs(ent.velocity.y) < EPSILON)
                    ent.velocity.y = 0;
        
                ent.pos_offset.x += ent.velocity.x * time_step;
                ent.pos_offset.y += ent.velocity.y * time_step;

                applyMove(row, col);
                
            }
        }
    }
}

Entity &Solver::getEntity(int row,  int col) {
    return m_entities->at(row * m_width + col);
}

void Solver::applyGravity( int row,  int col, float gravity) {
    Entity &ent = getEntity(row, col);
    ent.velocity.y += gravity * time_step;
    // ent.pos_offset.y += gravity * time_step * time_step * 0.5;
}

inline bool Solver::isEmpty(int row,  int col) {
    if (!inBounds(row, col)) return false;
    return getEntity(row, col).type == EntityType::EMPTY;
}

bool Solver::interpolate( int row,  int col,  int &target_row,  int &target_col) {
    if (row == target_row && col == target_col) return true;

    int dx = std::abs(target_col - col);
    int dy = -std::abs(target_row - row);

    int s_x, s_y;
    if (col <  target_col) {
        s_x = 1;
    } else {
        s_x = -1;
    }

    if (row < target_row) {
        s_y = 1;
    } else {
        s_y = -1;
    }

    int e = dx + dy;

    for (;;) {
        int prev_row = row;
        int prev_col = col;

        // printf("Current Position (%d, %d)\n", row, col);

        if (row == target_row && col == target_col) break;

        int ee = 2 * e;
        if (ee >= dy) {
            if (col == target_col) break;
            e += dy;
            col += s_x;

            if (!inBounds(row, col) || !isEmpty(row, col)) { 
                target_col = prev_col;
                target_row = prev_row;
                return true;
            }
        }

        if (ee <= dx) {
            if (row == target_row) break;
            e += dx;
            row += s_y;

            if (!inBounds(row, col) || !isEmpty(row, col)) { 
                target_col = prev_col;
                target_row = prev_row;
                return true;
            }
        }
    }

    return false;
}


// move to position if there's room, otherwise interpolate.
bool Solver::applyMove( int row,  int col,  int new_row,  int new_col, bool is_interpolate) {
    // Check if the move is within the boundaries
    new_row = std::clamp(new_row, 0, m_height - 1);
    new_col = std::clamp(new_col, 0, m_width - 1);

    if (isEmpty(row, col)) {
        return false;
    } 

    if (is_interpolate)
        interpolate(row, col, new_row, new_col);

    std::swap(getEntity(row, col), getEntity(new_row, new_col));
    return true;
}

bool Solver::applyMove(int row, int col, bool is_interpolate) {
    Entity &ent = getEntity(row, col);
    if (isEmpty(row, col)) {return false;}

    bool changed = false;
    int next_col = col;
    int next_row = row;

    int dx = ent.pos_offset.x;
    int dy = ent.pos_offset.y;

    if (dx != 0) {
        next_col += dx;
        ent.pos_offset.x -= dx;
        changed = true;
    }
    if (dy != 0) {
        next_row += dy;
        ent.pos_offset.y -= dy;
        changed = true;
    }

    if (changed) {
        if (is_interpolate && interpolate(row, col, next_row, next_col)) {
            // printf("dx, dy: %d, %d\n", dx, dy);
            checkCollision(row, col, dy, dx);
        }
        
        std::swap(getEntity(row, col), getEntity(next_row, next_col));
        return true;
    }

    return false;
}   

bool Solver::applyVelocity(int row,  int col) {
    Entity &ent = getEntity(row, col);

    if (ent.type == EntityType::EMPTY) return false;

    // apply velocity
    float vy = ent.velocity.y * time_step;
    float vx = ent.velocity.x * time_step;
    int target_row = row + (int) std::lround(vy);
    int target_col = col + (int) std::lround(vx);

    int og_target_row = target_row;
    int og_target_col = target_col;

    // std::cout << "Target Position (" << target_row << ", " << target_col << ")" << std::endl;
    if (interpolate(row, col, target_row, target_col)) {
        // handle collision
        int dx = std::clamp(og_target_col - col, -1, 1);
        int dy = std::clamp(og_target_row - row, -1, 1);
        // well it should be -1 and 1 at this point.
        // std::cout << "dx, dy: " << dx << ", " << dy << std::endl;

        // TODO this aint working! fix this, it seems really bad right now

        // we assume that direct diagonal movement is not possible, collisions
        // only occur on vertical or horizontal faces.
    }
    // std::cout << "Target Position 2 (" << target_row << ", " << target_col << ")" << std::endl;
    // printf("Target Position 2 (%d, %d)\n", target_row, target_col);
    // printf("velocity (%f, %f)\n", ent.velocity.x, ent.velocity.y);
    // printf("%f, %d\n", ent.velocity.y * time_step, (int) std::lround(ent.velocity.y * time_step));

    applyMove(row, col, true);

    ent.pos_offset.x += ent.velocity.y * time_step;
    ent.pos_offset.y += ent.velocity.x * time_step;
    //applyMove(row, col, target_row, target_col, false);

    return true;
}

void Solver::checkCollision(int row, int col, int dy, int dx) {
    if (dy == 0) {
        int n1_row = row;
        int n1_col = col + dx;

        if (!isEmpty(n1_row, n1_col) || !inBounds(n1_row, n1_col)) {
            // printf("Collision\n");
            applyCollision(row, col, n1_row, n1_col);
        }
    } else if (dx == 0) {
        int n1_row = row + dy;
        int n1_col = col;

        if (!isEmpty(n1_row, n1_col) || !inBounds(n1_row, n1_col)) {
            applyCollision(row, col, n1_row, n1_col);
        }
    } else {
        // collision neighbours
        int n1_row = row + dy;
        int n1_col = col;

        // collision neighbours
        int n2_row = row;
        int n2_col = col + dx;

        if (!isEmpty(n1_row, n1_col) || !inBounds(n1_row, n1_col)) {
            applyCollision(row, col, n1_row, n1_col);
        } 
        
        if (!isEmpty(n2_row, n2_col) || !inBounds(n2_row, n2_col)) {
            applyCollision(row, col, n2_row, n2_col);
        } 
    }
}

void Solver::applyCollision(int row1,  int col1,  int row2,  int col2) {
    Entity &ent1 = getEntity(row1, col1);

    if (!inBounds(row2, col2)) {
        if (row2 >= m_height || row2 < 0) {
            ent1.velocity.y = -ent1.velocity.y;
        }

        if (col2 >= m_width || col2 < 0) {
            ent1.velocity.x = -ent1.velocity.x;
        }
        return;
    }


    Entity &ent2 = getEntity(row2, col2);

    float elasticity = ent1.elasticity * ent2.elasticity;

    // apply collision forces
    if (row1 == row2) {
        // horizontal collision
        float v1 = ent1.velocity.x;
        float v2 = ent2.velocity.x;

        ent1.temperature = ENERGY_TO_TEMP * (1 - elasticity) * 0.5 * ent1.mass * v1 * v1 / ent1.specific_heat;
        ent2.temperature = ENERGY_TO_TEMP * (1 - elasticity) * 0.5 * ent2.mass * v2 * v2 / ent2.specific_heat;

        if (ent2.is_moveable) {
            ent1.velocity.x = ((ent1.mass - ent2.mass) * v1 + 2 * ent2.mass * v2) / (ent1.mass + ent2.mass) * elasticity;
            ent2.velocity.x = ((ent2.mass - ent1.mass) * v2 + 2 * ent1.mass * v1) / (ent1.mass + ent2.mass) * elasticity;
        } else {
            ent1.velocity.x = -v1 * elasticity;
            ent2.velocity.x = 0;
        }
    } else if (col1 == col2) {
        // vertical collision
        float v1 = ent1.velocity.y;
        float v2 = ent2.velocity.y;

        ent1.temperature = ENERGY_TO_TEMP * (1 - elasticity) * 0.5 * ent1.mass * v1 * v1 / ent1.specific_heat * elasticity;
        ent2.temperature = ENERGY_TO_TEMP * (1 - elasticity) * 0.5 * ent2.mass * v2 * v2 / ent2.specific_heat * elasticity;

        if (ent2.is_moveable) {
            ent1.velocity.y = ((ent1.mass - ent2.mass) * v1 + 2 * ent2.mass * v2) / (ent1.mass + ent2.mass) * elasticity;
            ent2.velocity.y = ((ent2.mass - ent1.mass) * v2 + 2 * ent1.mass * v1) / (ent1.mass + ent2.mass) * elasticity;
        } else {
            ent1.velocity.y = -v1 * elasticity;
            ent2.velocity.y = 0;
        }
    } else {
        // diagonal collision
        // hmmm
    }
}

bool Solver::applyForces( int row,  int col) {
    Entity &ent = getEntity(row, col);

    if (ent.type == EntityType::EMPTY) return false;

    // apply forces

    return true;
}

bool Solver::applyFriction(int row, int col) {
    Entity &ent = getEntity(row, col);
    float mass = ent.mass;

    if (ent.type == EntityType::EMPTY) return false;

    // determine direction of travel in the four directions
    
    if (ent.velocity.x > 0 && ent.velocity.y > 0) {         // quad 1
        if (inBounds(row, col + 1) && !isEmpty(row, col + 1)) {
            Entity &ent2 = getEntity(row, col + 1);
            float friction_force = std::clamp(std::max(ent.friction, ent2.friction) * ent.velocity.x, 0.0f, ent.velocity.y);
            ent.velocity.y -= friction_force;
            ent2.velocity.y += friction_force * mass / ent2.mass;
        }  
        if (inBounds(row + 1, col) && !isEmpty(row + 1, col)) {
            Entity &ent2 = getEntity(row + 1, col);
            float friction_force = std::clamp(std::max(ent.friction, ent2.friction) * ent.velocity.y, 0.0f, ent.velocity.x);
            ent.velocity.x -= friction_force;
            ent2.velocity.x += friction_force * mass / ent2.mass;
        }
    } else if (ent.velocity.x < 0 && ent.velocity.y > 0) { // quad 2
        if (inBounds(row, col - 1) && !isEmpty(row, col - 1)) {
            Entity &ent2 = getEntity(row, col - 1);
            float friction_force = std::clamp(std::max(ent.friction, ent2.friction) * std::abs(ent.velocity.x), 0.0f, ent.velocity.y);
            ent.velocity.y -= friction_force;
            ent2.velocity.y += friction_force * mass / ent2.mass;
        }
        if (inBounds(row + 1, col) && !isEmpty(row + 1, col)) {
            Entity &ent2 = getEntity(row + 1, col);
            float friction_force = std::clamp(std::max(ent.friction, ent2.friction) * ent.velocity.y, 0.0f, std::abs(ent.velocity.x));
            ent.velocity.x += friction_force;
            ent2.velocity.x -= friction_force * mass / ent2.mass;
        }
    } else if (ent.velocity.x < 0 && ent.velocity.y < 0) { // quad 3
        if (inBounds(row, col - 1) && !isEmpty(row, col - 1)) {
            Entity &ent2 = getEntity(row, col - 1);
            float friction_force = std::clamp(std::max(ent.friction, ent2.friction) * std::abs(ent.velocity.x), 0.0f, std::abs(ent.velocity.y));
            ent.velocity.y += friction_force;
            ent2.velocity.y -= friction_force * mass / ent2.mass;
        }
        if (inBounds(row - 1, col) && !isEmpty(row - 1, col)) {
            Entity &ent2 = getEntity(row - 1, col);
            float friction_force = std::clamp(std::max(ent.friction, ent2.friction) * std::abs(ent.velocity.y), 0.0f, std::abs(ent.velocity.x));
            ent.velocity.x += friction_force;
            ent2.velocity.x -= friction_force * mass / ent2.mass;
        }
    } else if (ent.velocity.x > 0 && ent.velocity.y < 0) { // quad 4
        if (inBounds(row, col + 1) && !isEmpty(row, col + 1)) {
            Entity &ent2 = getEntity(row, col + 1);
            float friction_force = std::clamp(std::max(ent.friction, ent2.friction) * ent.velocity.x, 0.0f, std::abs(ent.velocity.y));
            ent.velocity.y += friction_force;
            ent2.velocity.y -= friction_force * mass / ent2.mass;
        }
        if (inBounds(row - 1, col) && !isEmpty(row - 1, col)) {
            Entity &ent2 = getEntity(row - 1, col);
            float friction_force = std::clamp(std::max(ent.friction, ent2.friction) * std::abs(ent.velocity.y), 0.0f, ent.velocity.x);
            ent.velocity.x -= friction_force;
            ent2.velocity.x += friction_force * mass / ent2.mass;
        }
    }

    // apply friction

    return true;

}

bool Solver::applyDelta(int &row,  int &col,  int delta_row,  int delta_col) {
    row += delta_row;
    col += delta_col;

    bool in_bounds = row >= 0 && row < m_height && col >= 0 && col < m_width;
    if (!in_bounds) {
        row = std::clamp(row, 0, m_height - 1);
        col = std::clamp(col, 0, m_width - 1); 
    }

    return in_bounds;
}

inline bool Solver::inBounds( int row,  int col) {
    return row >= 0 && row < m_height && col >= 0 && col < m_width;
}
