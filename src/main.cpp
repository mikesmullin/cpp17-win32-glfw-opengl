// see: http://glew.sourceforge.net/basic.html
#include <GL/glew.h>
// see: https://www.glfw.org/documentation.html
#include <GLFW/glfw3.h>

#include <iostream>

#include "Renderer.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "VertexAttributeArray.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"

int main(void)
{
  GLFWwindow* window;

  /* Initialize the library */
  if (!glfwInit())
      return -1;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window)
  {
      glfwTerminate();
      return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  glfwSwapInterval(1); // refresh rate locked to vsync

  if (glewInit() != GLEW_OK)
  {
    std::cout << "Error!" << std::endl;
  }

  {
    float positions[] = {
      -0.5f, -0.5f, // 0
        0.5f, -0.5f, // 1
        0.5f,  0.5f, // 2
      -0.5f,  0.5f  // 3
    };

    unsigned int indices[] = {
      0, 1, 2,
      2, 3, 0
    };

    Renderer renderer;
    renderer.DebugLogVersion();

    VertexArray vao(1);
    VertexBuffer vbo(positions, 4 * 2 * sizeof(float));
    VertexAttributeArray vaa(0, 2);
    IndexBuffer ib(indices, 6);
    Shader shader("res/shaders/Basic.shader");
    int colorId = shader.GetUniformId("u_Color");

    // clear state
    shader.Unbind();
    vao.Unbind();

    float r = 0.0f;
    float increment = 0.05f;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
      renderer.Clear();
      renderer.Bind(vao, shader);
      shader.SetUniform4f(colorId, r, 0.3f, 0.8f, 1.0f);
      renderer.Draw();

      if (r > 1.0f)
      {
        increment = -0.05f;
      }
      else if ( r < 0.0f)
      {
        increment = 0.05f;
      }
      r += increment;

      // Swap front and back buffers
      glfwSwapBuffers(window);

      // Poll for and process events
      glfwPollEvents();
    }
  }

  glfwTerminate();
  return 0;
}