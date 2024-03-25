#include "renderer/Renderer.h"

void GlClearError() {
	while (glGetError() != GL_NO_ERROR);
}

bool GlLogCall(const char *function, const char *file, int line) {
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGL Error] (" << error << ") " << function  << " " << file << ":" << line << std::endl;
		return false;
	}
	return true;
}

Renderer::Renderer() {
	GLCall(glGenVertexArrays(1, &VAO)); 
	GLCall(glBindVertexArray(VAO));
}

Renderer::~Renderer() {
	glDeleteVertexArrays(1, &VAO);
}



void Renderer::clear() const {
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}