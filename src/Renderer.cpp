//
// Created by Jakub Pietrzak on 05/12/2023.
//

#include "Renderer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"


void Renderer::draw(const VertexArray &vertexArray, const IndexBuffer &indexBuffer, const Shader &shader) const
{
    shader.bind();
    vertexArray.bind();
    indexBuffer.bind();
    GLCall(glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::clear() const
{
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}
