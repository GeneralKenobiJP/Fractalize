//
// Created by Jakub Pietrzak on 09/12/2023.
//

#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define ASSERT(x) if(!(x)) __builtin_trap();
#define GLCall(x) GLClearError(); \
    x;                            \
    ASSERT(GLLogCall(__FILE__,__LINE__))

void GLClearError();
bool GLLogCall(const char* file, int line);
