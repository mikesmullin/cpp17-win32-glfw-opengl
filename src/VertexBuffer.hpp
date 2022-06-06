#pragma once

class VertexBuffer // VBO
{
private:
  unsigned int m_RendererId;
public:
  VertexBuffer(const void* data, unsigned int size);
  ~VertexBuffer();
  
  void Bind() const;
  void Unbind() const;
};