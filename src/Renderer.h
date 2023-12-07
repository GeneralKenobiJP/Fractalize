//
// Created by Jakub Pietrzak on 05/12/2023.
//

#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define ASSERT(x) if(!(x)) __builtin_trap();
#define GLCall(x) Renderer::GLClearError(); \
    x;                            \
    ASSERT(Renderer::GLLogCall(__FILE__,__LINE__))
#if false
#endif

class Renderer
{
public:
    static void GLClearError();

    static bool GLLogCall(const char* file, int line);

};
