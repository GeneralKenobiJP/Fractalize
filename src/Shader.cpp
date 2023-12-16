//
// Created by Jakub Pietrzak on 08/12/2023.
//

#include "Shader.h"
#include "GLM/glm/gtc/type_ptr.hpp"

Shader::Shader(const std::string &filepath)
    : filepath(filepath), rendererID(0)
{
    ShaderProgramSource source = parseShader(filepath);
    rendererID = createShader(source.vertexSource, source.fragmentSource);
}

Shader::~Shader()
{
    GLCall(glDeleteProgram(rendererID));
}

ShaderProgramSource Shader::parseShader(const std::string& filepath)
{
    std::ifstream stream(filepath);

    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::stringstream ss[2];
    ShaderType shaderType = ShaderType::NONE;
    std::string line;
    while(getline(stream,line))
    {
        if(line.find("#shader") != std::string::npos)
        {
            if(line.find("vertex") != std::string::npos)
            {
                shaderType = ShaderType::VERTEX;
            }
            else if(line.find("fragment") != std::string::npos)
            {
                shaderType = ShaderType::FRAGMENT;
            }
        }
        else
        {
            ss[(int)shaderType] << line << '\n';
        }
    }

    return { ss[0].str(), ss[1].str() };
}

unsigned int Shader::compileShader(const std::string& source, unsigned int type)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*) alloca(length * sizeof (char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile " << type << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

unsigned int Shader::createShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(vertexShader, GL_VERTEX_SHADER);
    unsigned int fs = compileShader(fragmentShader, GL_FRAGMENT_SHADER);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

void Shader::bind() const
{
    GLCall(glUseProgram(rendererID));
}

void Shader::unbind() const
{
    GLCall(glUseProgram(0));
}

void Shader::setUniform(const std::string &name, float v0, float v1, float v2, float v3)
{
    GLCall(glUniform4f(getUniformLocation(name), v0, v1, v2, v3));
}
void Shader::setUniform(const std::string &name, float v0, float v1, float v2)
{
    GLCall(glUniform3f(getUniformLocation(name), v0, v1, v2));
}
void Shader::setUniform(const std::string &name, float v0, float v1)
{
    GLCall(glUniform2f(getUniformLocation(name), v0, v1));
}
void Shader::setUniform(const std::string &name, float v0)
{
    GLCall(glUniform1f(getUniformLocation(name), v0));
}

int Shader::getUniformLocation(const std::string &name)
{
    if(uniformLocationCache.find(name) != uniformLocationCache.end())
        return uniformLocationCache[name];

    GLCall(int location = glGetUniformLocation(rendererID, name.c_str()));
    if(location == -1)
        std::cout << "Warning: uniform " << name << " doesn't exist!" << std::endl;

    uniformLocationCache[name] = location;
    return location;
}

void Shader::setUniformVecArray(const std::string &name, int count, const glm::vec4 *vecArray)
{
    GLCall(glUniform4fv(getUniformLocation(name), count, glm::value_ptr(vecArray[0])));
}


