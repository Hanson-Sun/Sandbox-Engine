#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>

#include "renderer/Renderer.h"
#include "renderer/VertexBuffer.h"
#include "renderer/IndexBuffer.h"
#include "renderer/VertexArray.h"
#include "renderer/VertexBufferLayout.h"
#include "renderer/Shader.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// glfw window creation
	// --------------------
	GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Wow this sucks", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glfwSwapInterval(2);
	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	// render loop
	// -----------
	{
		float positions[] = {
			-0.5f,  -0.5f,
			0.5f,  -0.5f,
			0.5f,  0.5f,
			-0.5f,  0.5f,
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		unsigned int VAO; 
		glGenVertexArrays(1, &VAO); 
		glBindVertexArray(VAO);

		VertexArray va;
		VertexBuffer vb(positions, 6 * 2 * sizeof(float));
		VertexBufferLayout layout;
		layout.push<float>(2);
		va.addBuffer(vb, layout);

		IndexBuffer ib(indices, 6);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		Shader shader = Shader("res/shaders/basic.shader");
		shader.bind();
		shader.setUniform4f("u_color", glm::vec4(0.8f, 0.3f, 0.8f, 1.0f));

		va.unbind();

		float r = 0.0f;
		float increment = 0.05f;
		while (!glfwWindowShouldClose(window))
		{	
			// input
			// -----
			processInput(window);

			// render
			// ------
			// glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			
			shader.setUniform4f("u_color", glm::vec4(r, 0.3f, 0.8f, 1.0f));
			glClear(GL_COLOR_BUFFER_BIT);

			va.bind();
			ib.bind();

			GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

			if (r > 1.0f) {
				increment = -0.05f;
			} else if (r < 0.0f) {
				increment = 0.05f;
			}

			r += increment;


			// glDrawArrays(GL_TRIANGLES, 0, 6);

			// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
			// -------------------------------------------------------------------------------
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and
	// height will be significantly larger than specified on retina displays.
	window  = window;
	glViewport(0, 0, width, height);
}