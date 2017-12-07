#include "StdInc.h"
#include "shader.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const GLchar * path, ShaderType type)
{
    std::stringstream shaderStream;
    std::ifstream shaderFile;
    shaderFile.open(path);

    shaderStream << shaderFile.rdbuf();
    shaderFile.close();

	std::string code = shaderStream.str();
    auto shaderCode = code.c_str();

    initShader(type);
    glShaderSource(ID, 1, &shaderCode, nullptr);
	compileShader();
}

GLuint Shader::getID()
{
    return ID;
}

void Shader::initShader(ShaderType type)
{
    switch(type)
    {
        case ShaderType::VERTEX_SHADER :
            ID = glCreateShader(GL_VERTEX_SHADER);
            break;
        case ShaderType::FRAGMENT_SHADER :
            ID = glCreateShader(GL_FRAGMENT_SHADER);
            break;
    };
}

void Shader::setType(ShaderType shaderType)
{
	type = shaderType;
}

ShaderType Shader::getType()
{
	return type;
}

void Shader::compileShader()
{
	glCompileShader(getID());
}
