//
// Created by Jakub Pietrzak on 05/12/2023.
//

#pragma once


#include "VertexBuffer.h"
#include "BufferLayout.h"

class VertexArray
{
private:
    unsigned int rendererID;
public:
    VertexArray();
    ~VertexArray();

    void addBuffer(const VertexBuffer& vertexBuffer, const BufferLayout& bufferLayout);

    void bind() const;
    void unbind() const;
};
