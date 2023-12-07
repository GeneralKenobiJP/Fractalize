//
// Created by Jakub Pietrzak on 05/12/2023.
//

#pragma once

#include <vector>

struct BufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int getTypeSize(unsigned int type);
};

class BufferLayout
{
private:
    std::vector<BufferElement> bufferElements;
    unsigned int stride;
public:
    BufferLayout();

    template<typename T>
    void push(unsigned int count);

    unsigned int getStride() const;

    const std::vector<BufferElement> &getBufferElements() const;
};

template<>
void BufferLayout::push<float>(unsigned int count);

template<>
void BufferLayout::push<unsigned int>(unsigned int count);

template<>
void BufferLayout::push<unsigned char>(unsigned int count);