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

void Renderer::draw(const VertexArray &va, const IndexBuffer &ib, const Texture &text, const Shader &shader) const {
	shader.bind();
	text.bind();
	va.bind();
	ib.bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::draw(const FrameBuffer &frame, const Shader &shader) const {
	shader.bind();
	std::printf("ok");
	frame.bind();
	std::cout << "okay" << std::endl;
	GLCall(glDrawArrays(GL_TRIANGLES, 0, 6));
	std::printf("okay!!");

	for (const Shader* const s : frame.shaders) {
		s->bind();
		GLCall(glDrawArrays(GL_TRIANGLES, 0, 6));
	}
	std::printf("okay!!!");
}

void Renderer::clear() const {
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}