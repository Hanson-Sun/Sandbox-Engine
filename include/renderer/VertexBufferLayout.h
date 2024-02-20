#pragma once
/**
 * so vertices can have complicated types, like a vertex with a position, color, and texture coordinates. 
 * This class is an abstraction that helps define the layout of a vertex.
 * 
 */

#include <vector>
#include <glad/glad.h>

#include "Renderer.h"

struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int getSizeOfType(unsigned int type) {
        switch (type) {
            case GL_FLOAT: return 4;
            case GL_UNSIGNED_INT: return 4;
            case GL_UNSIGNED_BYTE: return 1;
        }
        ASSERT(false);
        return 0;
    }
};

class VertexBufferLayout {
private:
    std::vector<VertexBufferElement> m_elements;
    unsigned int m_stride;
public:
    VertexBufferLayout() : m_stride(0) {};
    ~VertexBufferLayout() {};

    template<typename T>
    void push(unsigned int count) {
        std::cerr << "Unsupported data type\n";
        assert(false);
    }

    void push(unsigned int type, unsigned int count, bool normalized) {
        m_elements.push_back({type, count, normalized});
        m_stride += VertexBufferElement::getSizeOfType(type) * count;
    }

    inline unsigned int getStride() const { return m_stride; }
    inline const std::vector<VertexBufferElement> getElements() const { return m_elements; }
};

template<>
void VertexBufferLayout::push<float>(unsigned int count);
template<>
void VertexBufferLayout::push<unsigned int>(unsigned int count);
template<>
void VertexBufferLayout::push<unsigned char>(unsigned int count);