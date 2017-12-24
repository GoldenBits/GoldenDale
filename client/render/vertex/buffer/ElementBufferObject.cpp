#include "StdInc.h"

#include "ElementBufferObject.h"

void ElementBufferObject::genBuffer()
{
	glGenBuffers(1, &ID);
}

void ElementBufferObject::bindBuffer()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void ElementBufferObject::bufferData()
{
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices)*indices.size(), &indices.front(), GL_STATIC_DRAW);
}
