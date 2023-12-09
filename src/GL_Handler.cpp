//
// Created by Jakub Pietrzak on 09/12/2023.
//

#include "GL_Handler.h"
#include <iostream>

void GLClearError()
{
    while(glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* file, int line)
{
    while(GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] (" << error << ")" << std::endl;
        std::cout << "At " << file << std::endl;
        std::cout << "Line: " << line << std::endl;
        return false;
    }
    return true;
}