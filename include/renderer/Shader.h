#pragma once

#include <glm/glm.hpp>
#include <string>
#include <glad/glad.h>

#include <unordered_map>

struct ShaderProgramSource {
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader {
private:
    std::string m_filepath;
    unsigned int m_rendererID;
    std::unordered_map<std::string, int> m_uniformLocationCache;

public:
    Shader(const std::string &filepath);
    ~Shader();

    void bind() const;
    void unbind() const;

    // base case
    void setUniforms() const {}

    // Recursive template function
    template<typename T, typename... Args>
    void setUniforms(const std::string& name, T value, Args... args) {
        setUniform(name, value);  // set the uniform
        setUniforms(args...);  // recursive call using pack expansion syntax
    }

    // Set uniforms
    template<typename T>
    void setUniform(const std::string &name, T value);

private:
    int getUniformLocation(const std::string &name);

    ShaderProgramSource parseShader(const std::string file_path);
    unsigned int compileShader(unsigned int type, const std::string &source);
    unsigned int createShader(const std::string &vertexShader, const std::string &fragmentShader);

};