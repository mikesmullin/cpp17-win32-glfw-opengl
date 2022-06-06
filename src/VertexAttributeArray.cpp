#include "Renderer.hpp"
#include "VertexAttributeArray.hpp"

VertexAttributeArray::VertexAttributeArray()
  : m_RendererId(0), m_Offset(0)
{
}

VertexAttributeArray::~VertexAttributeArray()
{
  GLCall(glDisableVertexAttribArray(m_RendererId));
}
