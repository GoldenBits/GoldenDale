#pragma once

#include <StdInc.h>

class Shader;

class ShaderProgram
{
public:
	ShaderProgram(){ID = glCreateProgram();}
	~ShaderProgram(){glDeleteShader(ID);}
	GLuint getID();
	void attachShader(Shader * shader);
	void linkProgram();
	void use();
	void SetMatrix4(const GLchar *name, const glm::mat4 &matrix, GLboolean useShader = false);
private:
	GLuint ID;
};

