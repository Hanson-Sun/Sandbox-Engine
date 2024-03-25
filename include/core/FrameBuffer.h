# pragma once
#include <vector>
#include "Entity.h"
#include "Shader.h"
#include "Texture.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

class FrameBuffer {
public:
    std::vector<Entity>* entities;

    unsigned int m_width, m_height;
    FrameBuffer(unsigned int width, unsigned int height, std::vector<Entity>* entities, unsigned int divisor = 1);
    ~FrameBuffer();

    void update(std::vector<Entity>* entities, unsigned int width, unsigned int height);
    void update(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
    void updateTextureBuffers();
    Entity &getEntity(unsigned int row, unsigned int col);

    void bind() const;
    void unbind() const;

private:
    std::vector<unsigned char> m_color_buffer;
    std::vector<unsigned char> m_accumulation_buffer;

    Texture* m_texture;
    VertexArray* m_vertex_array;
    VertexBuffer* m_vertex_buffer;

    unsigned int m_frame_buffer_ID;

};
