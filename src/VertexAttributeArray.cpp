#include "Renderer.hpp"
#include "VertexAttributeArray.hpp"

VertexAttributeArray::VertexAttributeArray(const unsigned int id, const unsigned int size)
  : m_RendererId(id), m_Size(size)
{
    VertexAttributeArray::Bind();

    // current VAO state updates VAA + VBO here
    GLCall(glVertexAttribPointer(
      m_RendererId, // index
      m_Size, // size
      GL_FLOAT, // type
      GL_FALSE,  // normalized
      sizeof(float) * m_Size, // stride
      0 // offset
    ));    
}

VertexAttributeArray::~VertexAttributeArray()
{
}

void VertexAttributeArray::Bind() const
{
  GLCall(glEnableVertexAttribArray(m_RendererId));
}

void VertexAttributeArray::Unbind() const
{
  GLCall(glDisableVertexAttribArray(m_RendererId));
}