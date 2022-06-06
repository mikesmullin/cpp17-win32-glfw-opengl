#pragma once

// see: http://glew.sourceforge.net/basic.html
#include <GL/glew.h>
#include <iostream>

#define ASSERT(x) if (!(x)) { \
    std::cout << __FILE__ << ":" << __LINE__ << ": Assertion failed: " << #x << std::endl; \
    __debugbreak(); \
  }
#define GLCall(x) GLClearError();\
  x;\
  ASSERT(GLLogCall())

void GLClearError();
bool GLLogCall();