#pragma once

#include <vector>

class Vertex;

class VertexBufferObject
{
public:
	void genBuffer();
	void bind();
	void unbind();
	void bufferData();
	void setVertices(std::vector<Vertex> vertexes);
private:
	GLuint ID;
	std::vector<Vertex> vertices;
};