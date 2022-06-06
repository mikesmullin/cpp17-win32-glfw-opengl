@echo on
REM run via Developer Command Prompt for VS 2019

REM cd resources/
REM echo clean...
REM del index.res
REM echo bundle...
REM rc.exe /r index.rc
REM cd ..

cd build/
echo clean...
del main.obj main.exe

echo compile and link...
REM see https://docs.microsoft.com/en-us/cpp/build/reference/compiler-command-line-syntax?view=msvc-170
REM see https://docs.microsoft.com/en-us/cpp/build/reference/d-preprocessor-definitions?view=msvc-170
REM see https://docs.microsoft.com/en-us/cpp/build/reference/i-additional-include-directories?view=msvc-170
REM see https://docs.microsoft.com/en-us/cpp/build/reference/libpath-additional-libpath?view=msvc-170
cl /EHsc /std:c++17 /MD ^
  /D GLEW_STATIC ^
  /I ../vendor/glfw-3.3.7/include ^
  /I ../vendor/glew-2.1.0/include ^
  ../src/main.cpp ^
  ../src/Renderer.cpp ^
  ../src/VertexArray.cpp ^
  ../src/VertexBuffer.cpp ^
  ../src/VertexAttributeArray.cpp ^
  ../src/IndexBuffer.cpp ^
  ../src/Shader.cpp ^
  /link user32.lib shell32.lib gdi32.lib opengl32.lib ^
  /LIBPATH:../vendor/glfw-3.3.7/lib-vc2019 glfw3.lib ^
  /LIBPATH:../vendor/glew-2.1.0/lib/Release/Win32 glew32s.lib 
cd ..
pause

echo execute...
build\main.exe
