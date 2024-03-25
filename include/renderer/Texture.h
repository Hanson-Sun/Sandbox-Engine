#pragma once

#include <string>
#include <vector>

class Texture {
public:
    Texture(const std::string &path);
    Texture(std::vector<unsigned char> &data, unsigned int width, unsigned int height);
    ~Texture();

    void bind(unsigned int slot = 0) const;
    void unbind() const;
    void update(std::vector<unsigned char> &data, unsigned int width, unsigned int height);
    void updatePixel(unsigned int index, unsigned char r, unsigned char g, unsigned char b, unsigned char a, bool update=false);
    void updateArea(unsigned int width, unsigned int height, unsigned int x, unsigned int y);

    inline int getWidth() const { return m_width; }
    inline int getHeight() const { return m_height; }
private:
    unsigned int m_rendererID;
    std::string m_filePath;
    unsigned char *m_localBuffer;
    int m_width, m_height, m_BPP;
};

