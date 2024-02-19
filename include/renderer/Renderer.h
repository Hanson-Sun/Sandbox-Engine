#pragma once

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#define ASSERT(x) if (!(x)) __builtin_trap();
#define GLCall(x) GlClearError();\
	x;\
	ASSERT(GlLogCall(#x, __FILE__, __LINE__))

void GlClearError();
bool GlLogCall(const char *function, const char *file, int line);


class Renderer {
public:

private:
};