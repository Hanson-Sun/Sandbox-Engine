#include "renderer/IndexBuffer.h"
#include "renderer/Renderer.h"

IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count) {
    ASSERT(sizeof(unsigned int) == sizeof(GLuint));

    m_count = count;
    GLCall(glGenBuffers(1, &m_rendererID));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}
IndexBuffer::~IndexBuffer() {
    GLCall(glDeleteBuffers(1, &m_rendererID));
}
void IndexBuffer::bind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
}
void IndexBuffer::unbind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}