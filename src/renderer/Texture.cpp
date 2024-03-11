#include <iostream>

#include "renderer/Texture.h"
#include "stb_image/stb_image.h"
#include "renderer/Renderer.h"

Texture::Texture(const std::string &path) : 
    m_filePath(path), m_localBuffer(nullptr), m_width(0), m_height(0), m_BPP(0) {

    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    stbi_set_flip_vertically_on_load(1);
    m_localBuffer = stbi_load(path.c_str(), &m_width, &m_height, &m_BPP, 4);

    GLCall(glGenTextures(1, &m_rendererID));
    GLCall(glBindTexture(GL_TEXTURE_2D, m_rendererID));

    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

    GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer));
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));

    if (m_localBuffer) {
        stbi_image_free(m_localBuffer);
        std::cout << "Texture loaded: " << path << std::endl;
    } else {
        std::cout << "Failed to load texture: " << path << std::endl;
    }
}

Texture::Texture(std::vector<unsigned char> &data, unsigned int width, unsigned int height) : 
    m_localBuffer(data.data()), m_width(width), m_height(height), m_BPP(4) {

    assert(data.size() == width * height * m_BPP);

    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    GLCall(glGenTextures(1, &m_rendererID));
    GLCall(glBindTexture(GL_TEXTURE_2D, m_rendererID));

    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

    GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer));
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}

Texture::~Texture() {
    GLCall(glDeleteTextures(1, &m_rendererID));
}

void Texture::bind(unsigned int slot) const {
    GLCall(glActiveTexture(GL_TEXTURE0 + slot));
    GLCall(glBindTexture(GL_TEXTURE_2D, m_rendererID));
}

void Texture::unbind() const {
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}

void Texture::update(std::vector<unsigned char> &data, unsigned int width, unsigned int height) {
    assert(data.size() == width * height * m_BPP);

    m_localBuffer = data.data();
    m_width = width;
    m_height = height;

    GLCall(glBindTexture(GL_TEXTURE_2D, m_rendererID));
    GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer));
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}

void Texture::updatePixel(unsigned int index, unsigned char r, unsigned char g, unsigned char b, unsigned char a, bool update) {
    m_localBuffer[index * 4] = r;
    m_localBuffer[index * 4 + 1] = g;
    m_localBuffer[index * 4 + 2] = b;
    m_localBuffer[index * 4 + 3] = a;

    if (update) {
        GLCall(glBindTexture(GL_TEXTURE_2D, m_rendererID));
        GLCall(glTexSubImage2D(GL_TEXTURE_2D, 0, index % m_width, index / m_width, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer + index * 4));
        GLCall(glBindTexture(GL_TEXTURE_2D, 0));
    }
}
