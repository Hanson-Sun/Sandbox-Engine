#include <glm/glm.hpp>
#include "Entity.h"
Entity::Entity(EntityType _type, unsigned char _color[4], bool _is_moveable, bool _is_destructable, 
          float _lifetime, float _mass, float _viscosity, float _t_strength, float _s_strength, 
          float _c_strength, float _elasticity, float _friction, float _temperature, 
          float _conductivity, float _specific_heat, float _melting_pt, float _boiling_pt, glm::vec2 _velocity, 
          glm::vec2 _acceleration, bool _is_updated) 
{
    type = _type;
    color[0] = _color[0];
    color[1] = _color[1];
    color[2] = _color[2];
    color[3] = _color[3];
    mass = _mass;
    viscosity = _viscosity;
    t_strength = _t_strength;
    s_strength = _s_strength;
    c_strength = _c_strength;
    elasticity = _elasticity;
    friction = _friction;
    temperature = _temperature;
    conductivity = _conductivity;
    specific_heat = _specific_heat;
    melting_pt = _melting_pt;
    boiling_pt = _boiling_pt;
    velocity = _velocity;
    acceleration = _acceleration;
    is_moveable = _is_moveable;
    is_destructable = _is_destructable;
    lifetime = _lifetime;
    is_updated = _is_updated;
    pos_offset = glm::vec2(0.0f, 0.0f);
}

Entity::Entity() : type(EntityType::CUSTOM), color{255, 0, 0, 255}, is_moveable(true), is_destructable(true),
                   lifetime(-1), mass(1), viscosity(0), t_strength(1), s_strength(1),
                   c_strength(1), elasticity(1), friction(0), temperature(273), conductivity(1),
                   specific_heat(1), melting_pt(273), boiling_pt(373), pos_offset(0.0f, 0.0f), velocity(0.0f, 0.0f),
                   acceleration(0.0f, 0.0f), is_updated(false) {}

Entity::~Entity() {

}