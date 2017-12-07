#include "StdInc.h"

#include "VertexArrayObject.h"

void VertexArrayObject::genVertexArray()
{
	glGenVertexArrays(1, &ID);
}

void VertexArrayObject::bindVertexArray()
{
	glBindVertexArray(ID);
}

void VertexArrayObject::enableAttribureArray(GLuint index)
{
	glEnableVertexAttribArray(index);
}

void VertexArrayObject::vertexAttributeConfiguration()
{
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 5*sizeof(GLfloat), (GLvoid*)0);
	enableAttribureArray(0);

	glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE, 5*sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
	enableAttribureArray(1);
}

void VertexArrayObject::unbind()
{
	glBindVertexArray(0);
}

VertexArrayObject::VertexArrayObject()
{
	genVertexArray();
}
