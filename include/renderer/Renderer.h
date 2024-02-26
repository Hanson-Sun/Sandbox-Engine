#pragma once

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "renderer/IndexBuffer.h"
#include "renderer/VertexArray.h"
#include "renderer/Shader.h"

#define ASSERT(x) if (!(x)) __builtin_trap();
#define GLCall(x) GlClearError();\
	x;\
	ASSERT(GlLogCall(#x, __FILE__, __LINE__))

void GlClearError();
bool GlLogCall(const char *function, const char *file, int line);


class Renderer {
public:
	void draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const;
	void clear() const;
private:
};