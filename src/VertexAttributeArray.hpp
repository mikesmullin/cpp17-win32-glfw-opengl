#pragma once

class VertexAttributeArray // VAA
{
private:
  unsigned int m_RendererId;
  unsigned int m_Size;
public:
  VertexAttributeArray(const unsigned int id, const unsigned int size);
  ~VertexAttributeArray();
};