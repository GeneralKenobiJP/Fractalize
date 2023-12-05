//
// Created by Jakub Pietrzak on 05/12/2023.
//

#include "Renderer.h"
#include <iostream>

void Renderer::GLClearError()
{
    while(glGetError() != GL_NO_ERROR);
}

bool Renderer::GLLogCall()
{
    while(GLenum error = glGetError())
    {
        std::cout << &"[OpenGL Error] (" [ error] << ")" << std::endl;
        return false;
    }
    return true;
}
