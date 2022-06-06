#pragma once
#include <string>

struct ShaderProgramSource
{
  std::string VertexSource;
  std::string FragmentSource;
};

class Shader
{
private:
  unsigned int m_RendererID;
  std::string m_FilePath;
public:
  Shader(const std::string& filePath);
  ~Shader();

  static unsigned int CompileShader(unsigned int type, const std::string& source);
  static ShaderProgramSource ParseShader(const std::string& filePath);

  void Bind() const;
  void Unbind() const;

  int GetUniformId(const std::string& name);
  void SetUniform4f(const int id, const float v0, const float v1, const float f2, const float f3) const;
};