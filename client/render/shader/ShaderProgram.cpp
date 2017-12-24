#include "ShaderProgram.h"
#include "shader.h"
#include "iostream"
GLuint ShaderProgram::getID()
{
	return ID;
}

void ShaderProgram::attachShader(Shader *shader)
{
	glAttachShader(getID(), shader->getID());
}

void ShaderProgram::linkProgram()
{
	int success;
	glLinkProgram(getID());
	glGetProgramiv(getID(), GL_LINK_STATUS, &success);
}

void ShaderProgram::use()
{
	glUseProgram(getID());
}

void ShaderProgram::SetMatrix4(const GLchar *name, const glm::mat4 &matrix, GLboolean useShader)
{
	glUniformMatrix4fv(glGetUniformLocation(getID(), name), 1, GL_FALSE, glm::value_ptr(matrix));
}
