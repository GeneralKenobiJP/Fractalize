//
// Created by Jakub Pietrzak on 05/12/2023.
//

#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "GL_Handler.h"

class Renderer
{
private:

public:

    void draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader) const;
    void clear() const;
};
