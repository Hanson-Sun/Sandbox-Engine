#include <glm/glm.hpp>

namespace Entity {
    class Entity {
        glm::vec2 position;
        glm::vec2 velocity;
        glm::vec2 acceleration;
        bool updated;
        int size;
        float mass;
        float viscosity;
        float t_strength;
        float s_strength;
        float c_strength;
        float elasticity;
        float friction;
        float temperature;
        float melting_pt;
        float is_moveable;
        float color[4];
        void (**fns)();

        Entity();
        ~Entity();
    };
};