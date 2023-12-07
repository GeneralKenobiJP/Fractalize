//
// Created by Jakub Pietrzak on 05/12/2023.
//

#include "BufferLayout.h"
#include "Renderer.h"

template<typename T>
void BufferLayout::push(unsigned int count)
{
    static_assert(false);
}

template<>
void BufferLayout::push<float>(unsigned int count)
{
    bufferElements.push_back({GL_FLOAT, count, GL_FALSE});
    stride += count * sizeof (GLfloat);
}

template<>
void BufferLayout::push<unsigned int>(unsigned int count)
{
    bufferElements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
    stride += count * sizeof (GLuint);
}

template<>
void BufferLayout::push<unsigned char>(unsigned int count)
{
    bufferElements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
    stride += count * sizeof(GLbyte);
}

const std::vector<BufferElement> &BufferLayout::getBufferElements() const
{
    return bufferElements;
}

unsigned int BufferLayout::getStride() const
{
    return stride;
}

BufferLayout::BufferLayout()
: stride(0)
{

}

unsigned int BufferElement::getTypeSize(unsigned int type)
{
    switch(type)
    {
        case GL_FLOAT: return 4;
        case GL_UNSIGNED_INT: return 4;
        case GL_UNSIGNED_BYTE: return 1;
    }
    ASSERT(false);
    return 0;
}
