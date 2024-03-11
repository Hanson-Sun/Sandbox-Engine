#include "core/FrameBuffer.h"
#include "renderer/Renderer.h"
#include "renderer/VertexBufferLayout.h"

FrameBuffer::FrameBuffer(unsigned int width, unsigned int height, std::vector<Entity> &entities) {
    m_width = width;
    m_height = height;
    entities = entities;
    shaders = std::vector<Shader*>();
    m_color_buffer = std::vector<unsigned char>(width * height * 4);
    m_accumulation_buffer = std::vector<unsigned char>(width * height * 4);

    float positions[] = {
        // pos, texture pos
        0,  	0, 		0.0f, 0.0f,
        (float) width,  0, 		1.0f, 0.0f,
        (float) width,  (float) height, 1.0f, 1.0f,
        0, 		(float) height, 0.0f, 1.0f
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
	};


    m_vertex_array = new VertexArray();
    m_vertex_buffer = new VertexBuffer(positions, 4 * 4 * sizeof(float));
    VertexBufferLayout layout;
    layout.push<float>(2);
    layout.push<float>(2);

    m_vertex_array->addBuffer(*m_vertex_buffer, layout);

    m_index_buffer = new IndexBuffer(indices, 6);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    updateTexture();


    m_texture = new Texture(m_color_buffer, width, height);
}

FrameBuffer::~FrameBuffer() {
    unbind();
    GLCall(glDeleteFramebuffers(1, &m_frame_buffer_ID));
    delete m_texture;
    delete m_vertex_array;
    delete m_vertex_buffer;
    delete m_index_buffer;
}

void FrameBuffer::addShader(Shader* shader) {
    shaders.push_back(shader);
}

void FrameBuffer::bind() const {
    // GLCall(glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_ID));
    // GLCall(glViewport(0, 0, m_width, m_height));
    // figure out how to use frame buffer properly
    m_vertex_array->bind();
    m_index_buffer->bind();
    m_texture->bind();
}
void FrameBuffer::unbind() const {
    // GLCall(glBindFramebuffer(GL_FRAMEBUFFER, 0));
    // figure out how to use frame buffer properly
    m_vertex_array->unbind();
    m_index_buffer->unbind();
    m_texture->unbind();
}

void FrameBuffer::update(std::vector<Entity> &_entities, unsigned int width, unsigned int height) {
    entities = entities;
    m_width = width;
    m_height = height;
}

Entity &FrameBuffer::getEntity(unsigned int row, unsigned int col) {
    return entities[row * m_width + col];
}

void FrameBuffer::updateTexture(){
    for (size_t i = 0; i < entities.size(); i++) {
        m_texture->updatePixel(i, entities[i].color[0], entities[i].color[1], entities[i].color[2], entities[i].color[3]);
    }
}