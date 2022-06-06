#include "Renderer.hpp"
#include "VertexArray.hpp"

unsigned int VertexArray::m_UsedIds;

VertexArray::VertexArray(const unsigned int id)
  : m_RendererId(id)
{
  GLCall(glGenVertexArrays(m_RendererId, &VertexArray::m_UsedIds));
  VertexArray::Bind();
}

VertexArray::~VertexArray()
{

}

void VertexArray::Bind() const
{
  GLCall(glBindVertexArray(m_RendererId));
}

void VertexArray::Unbind() const
{
  GLCall(glBindVertexArray(0));
}