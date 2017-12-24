#pragma once

#include "ShaderType.h"
#include <GL/glew.h>

class Shader
{
public:
	GLuint getID();
	void initShader(ShaderType type);
    Shader(const GLchar* path, ShaderType type);
	void setType(ShaderType shaderType);
	void compileShader();
	ShaderType getType();

public:
	GLuint ID;
	ShaderType type;
};
