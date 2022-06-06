#include <iostream>
#include <string>
#include "Renderer.hpp"
#include "VertexArray.hpp"
#include "Shader.hpp"

void GLClearError()
{
  while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall()
{
  while (GLenum error = glGetError())
  {
    std::cout << "[OpenGL Error] (" << error << ")" << std::endl;
    return false;
  }
  return true;
}

void Renderer::DebugLogVersion() const
{
  GLCall(std::cout << "OpenGL v" << glGetString(GL_VERSION) << std::endl);
}

void Renderer::Clear() const
{
  GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Bind(const VertexArray vao, const Shader shader) const
{
  vao.Bind();
  shader.Bind();
  // TODO: move shader.SetUniform*() here
}

void Renderer::Draw() const
{
  GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
}