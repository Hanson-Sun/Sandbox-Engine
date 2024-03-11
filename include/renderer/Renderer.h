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

#define ASSERT(x) if (!(x)) __builtin_trap();
#define GLCall(x) GlClearError();\
	x;\
	ASSERT(GlLogCall(#x, __FILE__, __LINE__))

void GlClearError();
bool GlLogCall(const char *function, const char *file, int line);


class Renderer {
public:
	Renderer();
	~Renderer();
	void draw(const VertexArray &va, const IndexBuffer &ib, const Texture &text, const Shader &shader) const;
	void draw(const FrameBuffer &frame, const Shader &shader) const;
	void clear() const;
private:
	unsigned int VAO;
};