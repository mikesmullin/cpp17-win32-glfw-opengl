#pragma once
#include "Renderer.hpp"
#include <iostream>

class VertexAttributeArray // VAA
{
private:
  unsigned int m_RendererId;
  unsigned int m_Offset;
public:
  VertexAttributeArray();
  ~VertexAttributeArray();

  template<typename T>
  void AddAttr(const unsigned int count, const bool normalized, const unsigned int stride) { static_assert(false); }

  template<>
  void AddAttr<float>(const unsigned int count, const bool normalized, const unsigned int stride)
  {
    GLCall(glEnableVertexAttribArray(m_RendererId));

    const unsigned int size = sizeof(float) * count;

    // current VAO state updates VAA + VBO here
    GLCall(glVertexAttribPointer(
      m_RendererId, // index
      count, // size
      GL_FLOAT, // type
      (true == normalized ? GL_TRUE : GL_FALSE), // normalized
      stride, // stride
      (const void*) m_Offset // offset
    ));

    std::cout << "id: " << m_RendererId << " count: " << count << " size: " << size << " offset: " << m_Offset << std::endl;

    m_Offset += size;
    m_RendererId++;
  }
};