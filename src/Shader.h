//
// Created by Jakub Pietrzak on 08/12/2023.
//

#pragma once


#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include "GL_Handler.h"

struct ShaderProgramSource
{
    std::string vertexSource;
    std::string fragmentSource;
};

class Shader
{
private:
    std::string filepath;
    unsigned int rendererID;
    std::unordered_map<std::string, int> uniformLocationCache;

public:
    Shader(const std::string &filepath);
    ~Shader();

    void bind() const;
    void unbind() const;

    ShaderProgramSource parseShader(const std::string& filepath);
    unsigned int compileShader(const std::string& source, unsigned int type);
    unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);

    // set uniforms
    void setUniform(const std::string &name, float v0, float v1, float v2, float v3);
    void setUniform(const std::string &name, float v0, float v1, float v2);
    void setUniform(const std::string &name, float v0, float v1);
    void setUniform(const std::string &name, float v0);
private:
    int getUniformLocation(const std::string &name);
};
