//
// Created by Jakub Pietrzak on 05/12/2023.
//

#include "VertexBuffer.h"
#include "Renderer.h"

VertexBuffer::VertexBuffer(const void *data, unsigned int size)
{
    glGenBuffers(1,&rendererID);
    glBindBuffer(GL_ARRAY_BUFFER, rendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, rendererID);
}

void VertexBuffer::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer()
{
    GLCall(glDeleteBuffers(1,&rendererID));
}
