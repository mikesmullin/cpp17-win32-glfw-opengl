@echo off
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
REM see https://docs.microsoft.com/en-us/cpp/build/reference/i-additional-include-directories?view=msvc-170
REM see https://docs.microsoft.com/en-us/cpp/build/reference/libpath-additional-libpath?view=msvc-170
cl ../main.cpp /std:c++17 /MD /I ../vendor/glfw/include /link user32.lib shell32.lib gdi32.lib opengl32.lib /LIBPATH:../vendor/glfw/lib-vc2019 glfw3.lib 
cd ..
pause

echo execute...
cd build/
main.exe
cd ..
