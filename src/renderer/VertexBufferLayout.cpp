#include "renderer/VertexBufferLayout.h"

template<>
void VertexBufferLayout::push<float>(unsigned int count) {
    m_elements.push_back({GL_FLOAT, count, false});
    m_stride += VertexBufferElement::getSizeOfType(GL_FLOAT) * count;
}

template<>
void VertexBufferLayout::push<unsigned int>(unsigned int count) {
    m_elements.push_back({GL_UNSIGNED_INT, count, false});
    m_stride += VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT) * count;
}

template<>
void VertexBufferLayout::push<unsigned char>(unsigned int count) {
    m_elements.push_back({GL_UNSIGNED_BYTE, count, true});
    m_stride += VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE) * count;
}
