#pragma once

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "renderer/IndexBuffer.h"
#include "renderer/VertexArray.h"
#include "renderer/Shader.h"
#include "renderer/OrthoCamera.h"
#include "renderer/Texture.h"
#include "core/FrameBuffer.h"

#ifdef _MSC_VER
    // MSVC
    #include <intrin.h>
    #define ASSERT(x) if (!(x)) __debugbreak();
#else
    // GCC
    #define ASSERT(x) if (!(x)) __builtin_trap();
#endif

#define GLCall(x) GlClearError();\
	x;\
	ASSERT(GlLogCall(#x, __FILE__, __LINE__))

void GlClearError();
bool GlLogCall(const char *function, const char *file, int line);


class Renderer {
public:
	Renderer();
	~Renderer();

	template<typename... Args>
	void draw(const VertexArray &va, const IndexBuffer &ib, const Texture &text, Shader &shader, Args... args) const {
		shader.bind();
		shader.setUniforms(args...); // bruh i hope this works :skull:
		text.bind();
		va.bind();
		ib.bind();
		GLCall(glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr));
	}

	template<typename... Args>
	void draw(const FrameBuffer &frame, Shader &shader, Args ... args) const {
		shader.bind();
		shader.setUniforms(args...); // bruh i hope this works :skull:
		frame.bind();
		// !!! fix
		GLCall(glDrawArrays(GL_TRIANGLE_STRIP, 0, 4));
	}

	void clear() const;
private:
	unsigned int VAO;
};