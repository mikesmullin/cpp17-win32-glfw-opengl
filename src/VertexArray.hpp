#pragma once

class VertexArray // VAO
{
private:
  unsigned int m_RendererId;
public:
  static unsigned int m_UsedIds;
  VertexArray(const unsigned int id);
  ~VertexArray();

  void Bind() const;
  void Unbind() const;  
};
