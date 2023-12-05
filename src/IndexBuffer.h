//
// Created by Jakub Pietrzak on 05/12/2023.
//

#pragma once


class IndexBuffer
{
private:
    unsigned int rendererID;
    unsigned int count;
public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    void bind() const;
    void unbind() const;

    inline unsigned int getCount() const;
};
