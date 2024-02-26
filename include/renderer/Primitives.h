#pragma once

#include <type_traits>
#include <glm/glm.hpp>

// maybe a polymorphic approach is better, expecially do get these primitives to generate the proper buffers.

struct Point2D {
    glm::vec3 coordinates;
};

struct Line2D {
    glm::vec3 start;
    glm::vec3 end;
};

struct Triangle2D {
    glm::vec3 a;
    glm::vec3 b;
    glm::vec3 c;
};

struct Quad2D {
    glm::vec3 a;
    glm::vec3 b;
    glm::vec3 c;
};

template <typename T>
struct Rect2D {
    static_assert(std::is_arithmetic<T>::value, "Template argument must be a numeric type");
    glm::vec3 pos;
    T width;
    T height;
};



