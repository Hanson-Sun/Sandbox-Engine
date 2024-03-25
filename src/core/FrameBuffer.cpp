#include "core/FrameBuffer.h"
#include "renderer/Renderer.h"
#include "renderer/VertexBufferLayout.h"

FrameBuffer::FrameBuffer(unsigned int width, unsigned int height, std::vector<Entity>* _entities, unsigned int divisor) {
    m_width = width / divisor;
    m_height = height / divisor;
    entities = _entities;
    assert(m_width * m_height == entities->size());
    m_color_buffer = std::vector<unsigned char>(m_width * m_height * 4);
    m_accumulation_buffer = std::vector<unsigned char>(m_width * m_height * 4);

    float positions[] = {
        // pos, texture pos
        0,  	        0, 		        0.0f, 0.0f,  // Bottom left corner
        (float) width,  0, 		        1.0f, 0.0f,  // Bottom right corner
        0, 		        (float) height, 0.0f, 1.0f,  // Top left corner
        (float) width,  (float) height, 1.0f, 1.0f   // Top right corner
    };


    m_vertex_array = new VertexArray();
    m_vertex_buffer = new VertexBuffer(positions, 4 * 4 * sizeof(float));
    VertexBufferLayout layout;
    layout.push<float>(2);
    layout.push<float>(2);

    m_vertex_array->addBuffer(*m_vertex_buffer, layout);
    m_vertex_array->unbind();
    m_vertex_buffer->unbind();
    // m_index_buffer->unbind();

    m_texture = new Texture(m_color_buffer, m_width, m_height);
    updateTextureBuffers();
    printf("Created Frame Buffer\n");
    
}

FrameBuffer::~FrameBuffer() {
    unbind();
    GLCall(glDeleteFramebuffers(1, &m_frame_buffer_ID));
    delete m_texture;
    delete m_vertex_array;
    delete m_vertex_buffer;
    // delete m_index_buffer;
}

void FrameBuffer::bind() const {
    // GLCall(glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_ID));
    // GLCall(glViewport(0, 0, m_width, m_height));
    m_vertex_array->bind();
    m_texture->bind();
}
void FrameBuffer::unbind() const {
    // GLCall(glBindFramebuffer(GL_FRAMEBUFFER, 0));
    // figure out how to use frame buffer properly
    m_vertex_array->unbind();
    m_texture->unbind();
}

void FrameBuffer::update(std::vector<Entity>* _entities, unsigned int width, unsigned int height) {
    entities = entities;
    m_width = width;
    m_height = height;
}

void FrameBuffer::update(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) {
    assert(x1 < x2 && y1 < y2);

    for (size_t i = y1; i < y2; i++) {
        for (size_t j = x1; j < x2; j++) {
            m_texture->updatePixel(i * m_width + j, entities->at(i * m_width + j).color[0], entities->at(i * m_width + j).color[1], entities->at(i * m_width + j).color[2], entities->at(i * m_width + j).color[3]);
        }
    }
}

Entity &FrameBuffer::getEntity(unsigned int row, unsigned int col) {
    return entities->at(row * m_width + col);
}

void FrameBuffer::updateTextureBuffers(){
    for (size_t i = 0; i < entities->size(); i++) {
        m_texture->updatePixel(i, entities->at(i).color[0], entities->at(i).color[1], entities->at(i).color[2], entities->at(i).color[3]);
    }
    m_texture->updateArea(m_width, m_height, 0, 0);
}