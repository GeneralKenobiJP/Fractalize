//
// Created by Jakub Pietrzak on 05/12/2023.
//

#include "IndexBuffer.h"
#include "GL_Handler.h"

IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count)
: count(count)
{
    glGenBuffers(1,&rendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

void IndexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, rendererID);
}

void IndexBuffer::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1,&rendererID));
}

unsigned int IndexBuffer::getCount() const
{
    return count;
}
