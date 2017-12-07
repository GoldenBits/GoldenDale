#include "StdInc.h"

#include "VertexBufferObject.h"
#include "render/vertex/Vertex.h"

void VertexBufferObject::genBuffer()
{
	glGenBuffers(1, &ID);
}

void VertexBufferObject::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VertexBufferObject::bufferData()
{
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices.front(), GL_DYNAMIC_DRAW);
}

void VertexBufferObject::setVertices(std::vector<Vertex> vertexes)
{
	vertices = vertexes;
}

void VertexBufferObject::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}