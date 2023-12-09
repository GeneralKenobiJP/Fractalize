//
// Created by Jakub Pietrzak on 05/12/2023.
//

#include "VertexArray.h"
#include "GL_Handler.h"

VertexArray::VertexArray()
{
    GLCall(glGenVertexArrays(1, &rendererID));
}

VertexArray::~VertexArray()
{
    GLCall(glDeleteVertexArrays(1, &rendererID));
}

void VertexArray::addBuffer(const VertexBuffer &vertexBuffer, const BufferLayout &bufferLayout)
{
    bind();
    vertexBuffer.bind();
    const auto& elements = bufferLayout.getBufferElements();
    unsigned int offset = 0;
    for(unsigned int i=0; i<elements.size(); i++)
    {
        const auto& element  = elements[i];
        GLCall(glEnableVertexAttribArray(i));
        GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, bufferLayout.getStride(), (const void*) offset));
        offset += element.count * BufferElement::getTypeSize(element.type);
    }
}

void VertexArray::bind() const
{
    GLCall(glBindVertexArray(rendererID));
}

void VertexArray::unbind() const
{
    GLCall(glBindVertexArray(0));
}
