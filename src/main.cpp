#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <unistd.h>

#include "renderer/Renderer.h"
#include "renderer/VertexBuffer.h"
#include "renderer/IndexBuffer.h"
#include "renderer/VertexArray.h"
#include "renderer/VertexBufferLayout.h"
#include "renderer/Shader.h"
#include "renderer/Texture.h"
#include "renderer/OrthoCamera.h"
#include "FrameBuffer.h"
#include "Solver.h"


#include "core/Entity.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;
float gravity = -5;


void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		gravity = 5;
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
		unsigned int divisor = 2;

		unsigned int width = SCR_WIDTH / divisor;
		unsigned int height = SCR_HEIGHT / divisor;

		OrthoCamera cam(0, 1 * SCR_WIDTH, 0, 1 * SCR_HEIGHT);
		cam.setPosition({0, 0, 1});
		cam.setRotation(0);


		Renderer renderer;
		unsigned int VAO; 
		GLCall(glGenVertexArrays(1, &VAO)); 
		GLCall(glBindVertexArray(VAO));

		
		std::vector<Entity> entities(width * height);
		for (size_t i = 0; i < height * width; i++) {


			if (rand() < 13000) {
				// unsigned char yellow[4] = {255, 255, 0, 255};
				unsigned char color[4] = { static_cast<float>(rand()) / RAND_MAX * 255,
							static_cast<float>(rand()) / RAND_MAX * 255,
							static_cast<float>(rand()) / RAND_MAX * 255,
							255 };
				Entity ent = Entity(EntityType::SOLID, color);
				ent.velocity = {static_cast<float>(rand()) / RAND_MAX * 40 - 20, 0};
				ent.elasticity = 0.995;
				ent.friction = 0.005;
				ent.mass = static_cast<float>(rand()) / RAND_MAX * 10 + 10;
				entities[i] = ent;
			} else {
				unsigned char color[4] = { 0, 0, 0, 255 };
				entities[i] = Entity(EntityType::EMPTY, color);
			}
		}

		// for (size_t i = 0; i < width; i++) {
		// 	unsigned char color[4] = { static_cast<float>(rand()) / RAND_MAX * 255,
		// 				static_cast<float>(rand()) / RAND_MAX * 255,
		// 				static_cast<float>(rand()) / RAND_MAX * 255,
		// 				255 };
		// 	Entity ent = Entity(EntityType::SOLID, color);
		// 	ent.velocity = {static_cast<float>(rand()) / RAND_MAX * 40 - 20, 0};
		// 	ent.elasticity = 0.98;
		// 	ent.friction = 0.1;
		// 	entities[i] = ent;
		// }

		unsigned char yellow[4] = {255,255,0,255 };
		unsigned char red[4] = {255,0,0,255 };

		Entity ent1 = Entity(EntityType::SOLID, yellow);
		Entity ent2 = Entity(EntityType::SOLID, red);

		// ent1.velocity = {-20, 0};
		// ent2.velocity = {20, 0};

		ent1.friction = ent2.friction = 0.5;

		entities[width * (height * 0.0) + 1] 		= ent1;
		entities[width * (height * 0.0) + width - 2] = ent2;

		// Entity ent = Entity(EntityType::SOLID, yellow);
		// ent.velocity = {20, 0};
		// entities[width * (height - 10) + 30] = ent;



		Shader shader = Shader("C:\\Users\\docto\\Documents\\GitHub\\Sandbox-Engine\\res\\shaders\\texture.shader");
		shader.setUniforms("u_texture", 0, 
						    // "u_textureSize", glm::vec2(width, height),
						    "u_mvp", cam.getViewProjectionMatrix());
		// shader.setUniform<int>("u_texture", 0);
		// shader.setUniform<glm::vec2>("u_textureSize", {width, height});
		// shader.setUniform<glm::mat4>("u_mvp", cam.getViewProjectionMatrix());



		printf("Entities: %d\n", entities.size());

		FrameBuffer fb(SCR_WIDTH, SCR_HEIGHT, &entities, divisor);
		Solver solver(&entities, width, height, 0.05);

		while (!glfwWindowShouldClose(window)) {	
			std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
			processInput(window);
			// renderer.clear();
			double xpos, ypos;
			glfwGetCursorPos(window, &xpos, &ypos);
			ypos = ypos;
			xpos /= divisor;
			ypos /= divisor;

			// printf("X: %f, Y: %f\n", xpos, ypos);

			if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
				// The left mouse button is being pressed.
				Entity ent = Entity(EntityType::SOLID, red);
				ent.velocity = {100, -5000};
				ent.elasticity = 0.1;
				ent.mass = 1000;
				ent.friction = 0.1;
				entities[width * (int)(height - ypos) + (int)xpos] = ent;
				printf("Added entity at %d, %d\n", (int)xpos, (int)ypos);
			}

			
			fb.updateTextureBuffers();
			renderer.draw(fb, shader);
			// usleep(100000);

			solver.update();
			// solver.update(0, height);

			// renderer.draw(*m_vertex_array, *m_index_buffer, *m_texture, shader,
			// 			  "u_texture", 0,
			// 			  "u_textureSize", glm::vec2(width, height),
			// 			  "u_mvp", cam.getViewProjectionMatrix());
			// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
			// -------------------------------------------------------------------------------
			glfwSwapBuffers(window);
			glfwPollEvents();
			std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
			double frameTimeInSeconds = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0;
			printf("FPS: %f\n", 1.0 / frameTimeInSeconds);

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

			renderer.draw(va, ib, tx, shader);

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
