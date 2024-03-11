#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
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
#include "renderer/Texture.h"
#include "renderer/OrthoCamera.h"
#include "FrameBuffer.h"


#include "core/Entity.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 900;


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

#if true
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

	glfwSwapInterval(1);
	// glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// render loop
	{
		Renderer renderer;

		OrthoCamera cam(0, 1 * SCR_WIDTH, 0, 1 * SCR_HEIGHT);
		cam.setPosition({0, 0, 1});
		cam.setRotation(0);

		unsigned int entity_count = SCR_HEIGHT / 4 * SCR_WIDTH / 4;
		std::vector<Entity> entities(entity_count);
		for (size_t i = 0; i < entity_count; i++) {
			unsigned char color[4] = { static_cast<float>(rand()) / RAND_MAX * 255,
							   		   static_cast<float>(rand()) / RAND_MAX * 255,
							   		   static_cast<float>(rand()) / RAND_MAX * 255,
							  		   255 };
			entities[i] = Entity(EntityType::CUSTOM, color);
		}
			
		Shader shader = Shader("res/shaders/texture.shader");
		shader.setUniform<int>("u_texture", 0);
		shader.setUniform<glm::mat4>("u_mvp", cam.getViewProjectionMatrix());

		FrameBuffer fb(SCR_WIDTH, SCR_HEIGHT, entities);

		while (!glfwWindowShouldClose(window)) {	

			processInput(window);
			renderer.clear();


			renderer.draw(fb, shader);



			// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
			// -------------------------------------------------------------------------------
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
	glfwTerminate();
	return 0;
}
#endif

#if false
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

	glfwSwapInterval(1);
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
			// pos, texture pos
			0,  		 0, 		  0.0f, 0.0f,
			SCR_WIDTH ,  0, 		  1.0f, 0.0f,
			SCR_WIDTH ,  SCR_HEIGHT , 1.0f, 1.0f,
			0, 			 SCR_HEIGHT , 0.0f, 1.0f
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};
		
		OrthoCamera cam(0, 1 * SCR_WIDTH, 0, 1 * SCR_HEIGHT);
		cam.setPosition({0, 0, 1});
		cam.setRotation(30);

		unsigned int VAO; 
		glGenVertexArrays(1, &VAO); 
		glBindVertexArray(VAO);

		VertexArray va;
		VertexBuffer vb(positions, 4 * 4 * sizeof(float));
		VertexBufferLayout layout;
		layout.push<float>(2);
		layout.push<float>(2);

		va.addBuffer(vb, layout);

		IndexBuffer ib(indices, 6);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		Shader shader = Shader("res/shaders/texture.shader");
		shader.bind();
		shader.setUniform<int>("u_texture", 0);
		shader.setUniform<glm::mat4>("u_mvp", cam.getViewProjectionMatrix());

		va.unbind();
		vb.unbind();
		ib.unbind();

		Texture tx("res/textures/amog.png");
		tx.bind();

		Renderer renderer;

		float r = 0.0f;
		float increment = 0.05f;
		while (!glfwWindowShouldClose(window))
		{	
			// input
			// -----
			processInput(window);
			renderer.clear();

			// render
			// ------
			// glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			shader.bind();
			// shader.setUniform<glm::vec4>("u_color", glm::vec4(r, 0.3f, 0.8f, 1.0f));
			// 

			// va.bind();
			// ib.bind();

			renderer.draw(va, ib, shader);

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
#endif
