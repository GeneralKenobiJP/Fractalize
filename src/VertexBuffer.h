//
// Created by Jakub Pietrzak on 05/12/2023.
//

#pragma once

//this is vertex data
class VertexBuffer
{
private:
    unsigned int rendererID;
public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void bind() const;
    void unbind() const;

};
