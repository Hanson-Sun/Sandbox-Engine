#pragma once
#include <vector>
#include "core/Entity.h"

#define SQRT_2 1.41421356237
#define PI 3.14159265359
#define EPSILON 0.0001
#define ENERGY_TO_TEMP 0.01

// idk pick an arbiiary number bruh
#define BOLTZMANN 1

class Solver {
public:
    Solver(std::vector<Entity> *ents,  int width,  int height, float time_step);
    ~Solver();

    void update();
    void update(int row_begin, int row_end);


    float time_step;
private:
    int m_width, m_height;
    std::vector<Entity>* m_entities;

    Entity &getEntity( int row,  int col);
    void applyGravity( int row,  int col, float gravity);

    void conductTemperature( int row,  int col);
    void applyTemperatureForce();


    bool interpolate( int row,  int col,  int &target_row,  int &target_col);

    bool applyMove( int row,  int col,  int new_row,  int new_col, bool is_interpolate = true);
    bool applyMove(int row, int col, bool is_interpolate = true);

    bool applyVelocity( int row,  int col);
    bool applyForces( int row,  int col);

    bool applyDelta( int &row,  int &col, int delta_row, int delta_col);

    bool applyFriction( int row,  int col);

    void checkCollision(int row, int col, int dy, int dx);
    void applyCollision( int row1,  int col1,  int row2,  int col2);

    inline bool isEmpty( int row,  int col);
    inline bool inBounds( int row,  int col);

};