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


void Renderer::draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const {
	shader.bind();
	va.bind();
	ib.bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::clear() const {
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}