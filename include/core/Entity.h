#pragma once

#include <glm/glm.hpp>

struct EntityTextureVertex {
    float temperature;
    float color[4];
};

// empty type is required since if we want a vector of entities, not entity pointers.
enum class EntityType : int {
    CUSTOM, 
    VARIABLE,
    EMPTY, 
    SOLID,
    LIQUID,
    GAS
};

struct Entity {
    glm::vec2 pos_offset;
    glm::vec2 velocity;
    glm::vec2 acceleration;
    unsigned char color[4];
    float mass;
    float viscosity;
    float t_strength;
    float s_strength;
    float c_strength;
    float elasticity;
    float friction;
    float temperature;
    float conductivity;
    float specific_heat;
    float melting_pt;
    float boiling_pt;
    int lifetime;
    EntityType type = EntityType::EMPTY;
    bool is_moveable;
    bool is_destructable;
    bool is_updated;
    bool is_active;

    Entity();
    ~Entity();
    Entity(EntityType _type, unsigned char _color[4] , bool _is_moveable = true, bool _is_destructable = true, 
        float _lifetime = -1, float _mass = 1, float _viscosity = 0, float _t_strength = 1, float _s_strength = 1, 
        float _c_strength = 1, float _elasticity = 1, float _friction = 0, float _temperature = 273, 
        float _conductivity = 1, float specific_heat = 1, float _melting_pt = 273, float _boiling_pt = 373, glm::vec2 _velocity = glm::vec2(0.0f, 0.0f),
        glm::vec2 _acceleration = glm::vec2(0.0f, 0.0f), bool _is_updated = false);
};
