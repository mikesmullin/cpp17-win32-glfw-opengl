#include "Renderer.hpp"
#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
  GLCall(glGenBuffers(1, &m_RendererId));
  VertexBuffer::Bind();
  GLCall(glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
  GLCall(glDeleteBuffers(1, &m_RendererId));
}

void VertexBuffer::Bind() const
{
  GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererId));
}

void VertexBuffer::Unbind() const
{
  GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
