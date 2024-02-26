#include "renderer/Shader.h"

#include "renderer/Renderer.h"

#include <iostream>
#include <fstream>
#include <sstream>

Shader::Shader(const std::string &filepath) : 
    m_filepath(filepath), m_rendererID(0) {
        ShaderProgramSource source = parseShader(filepath);
        m_rendererID = createShader(source.VertexSource, source.FragmentSource);
}

Shader::~Shader() {
    GLCall(glDeleteProgram(m_rendererID));
}

void Shader::bind() const {
    GLCall(glUseProgram(m_rendererID));
}

void Shader::unbind() const {
    GLCall(glUseProgram(0));
}

ShaderProgramSource Shader::parseShader(const std::string file_path) {
	std::ifstream stream(file_path);

	assert(stream.is_open() && "Failed to open shader file");

	enum class ShaderType {
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2];

	ShaderType type = ShaderType::NONE;
	
	while (getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos) {
				type = ShaderType::VERTEX;
			} else if (line.find("fragment") != std::string::npos) {
				type = ShaderType::FRAGMENT;
			}
		} else {
			ss[(int)type] << line << '\n';
		}
	}

	return {ss[0].str(), ss[1].str()};
}

unsigned int Shader::compileShader(unsigned int type, const std::string &source) {
	unsigned int id = glCreateShader(type);
	const char *src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char *message = (char *) alloca(length * sizeof(char));
		std::cerr << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader! \n";
		std::cerr << message << std::endl;
		glDeleteShader(id);
		return 0;
	}
	return id;
}

unsigned int Shader::createShader(const std::string &vertexShader, const std::string &fragmentShader) {
	unsigned int program = glCreateProgram();
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);
	
	assert(vs != 0);
	assert(fs != 0);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);
	return program;
}

// Set uniforms
template<typename T>
void setUniform(const std::string &name, T value) {
	assert(false && "Unsupported uniform type");
}

template<>
void Shader::setUniform<int>(const std::string &name, int value) {
	glUniform1i(getUniformLocation(name), value);
}

template<>
void Shader::setUniform<float>(const std::string &name, float value) {
	glUniform1f(getUniformLocation(name), value);
}

template<>
void Shader::setUniform<glm::vec4>(const std::string &name, glm::vec4 value) {
	glUniform4f(getUniformLocation(name), value[0], value[1], value[2], value[3]);
}

template<>
void Shader::setUniform<glm::mat4>(const std::string &name, glm::mat4 value) {
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &value[0][0]);
}

int Shader::getUniformLocation(const std::string &name) {
    if (m_uniformLocationCache.find(name) != m_uniformLocationCache.end())
        return m_uniformLocationCache[name];

    GLCall(int location = glGetUniformLocation(m_rendererID, name.c_str()));
    if (location == -1)
        std::cout << "Warning: uniform " << name << " doesn't exist!" << std::endl;

    m_uniformLocationCache[name] = location;
    return location;
}

