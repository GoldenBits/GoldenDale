#pragma once

#include <vector>

class ElementBufferObject
{
public:
	void genBuffer();
	void bindBuffer();
	void bufferData();
private:
	GLuint ID;
	std::vector<GLuint> indices;
};