#include <fstream>
#include <string>
#include <sstream>

#include "Renderer.hpp"
#include "Shader.hpp"

Shader::Shader(const std::string& filePath)
  : m_FilePath(filePath)
{
  GLCall(m_RendererID = glCreateProgram());
  ShaderProgramSource src = Shader::ParseShader(filePath);
  unsigned int vs = Shader::CompileShader(GL_VERTEX_SHADER, src.VertexSource);
  unsigned int fs = Shader::CompileShader(GL_FRAGMENT_SHADER, src.FragmentSource);

  GLCall(glAttachShader(m_RendererID, vs));
  GLCall(glAttachShader(m_RendererID, fs));
  GLCall(glLinkProgram(m_RendererID));
  GLCall(glValidateProgram(m_RendererID));

  GLCall(glDeleteShader(vs));
  GLCall(glDeleteShader(fs));
}

Shader::~Shader()
{
    GLCall(glDeleteProgram(m_RendererID));
}

ShaderProgramSource Shader::ParseShader(const std::string& filePath)
{
  std::ifstream stream(filePath);

  enum class ShaderType
  {
    NONE = -1, VERTEX = 0, FRAGMENT = 1
  };
  std::string line;
  std::stringstream ss[2];
  ShaderType type = ShaderType::NONE;
  while (getline(stream, line)) 
  {
    if (line.find("#shader") != std::string::npos)
    {
      if (line.find("vertex") != std::string::npos)
      {
        type = ShaderType::VERTEX;
      }
      else if (line.find("fragment") != std::string::npos)
      {
        type = ShaderType::FRAGMENT;
      }
    }
    else {
      ss[(int)type] << line << '\n';
    }
  }

  return { ss[0].str(), ss[1].str() };
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
  GLCall(unsigned int id = glCreateShader(type));
  const char* src = source.c_str();
  GLCall(glShaderSource(id, 1, &src, nullptr));
  GLCall(glCompileShader(id));

  int result;
  GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
  if (result == GL_FALSE)
  {
    int length;
    GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
    char* message = (char*)alloca(length * sizeof(char));
    GLCall(glGetShaderInfoLog(id, length, &length, message));
    std::cout << "Failed to compile " <<
      (type == GL_VERTEX_SHADER ? "vertex" : "fragment") <<
      " shader!" << std::endl;
    std::cout << message << std::endl;
    GLCall(glDeleteShader(id));
    return 0;
  }

  return id;
}

void Shader::Bind() const
{
    GLCall(glUseProgram(m_RendererID));
}

void Shader::Unbind() const
{
    GLCall(glUseProgram(0));
}

int Shader::GetUniformId(const std::string& name)
{
    GLCall(int location = glGetUniformLocation(m_RendererID, name.c_str()));
    ASSERT(location != -1);
    return location;
}

void Shader::SetUniform4f(const int id, const float v0, const float v1, const float f2, const float f3) const
{
    GLCall(glUniform4f(id, v0, v1, f2, f3));
}

void Shader::SetUniform1i(const int id, const int i0) const
{
    GLCall(glUniform1i(id, i0));
}
