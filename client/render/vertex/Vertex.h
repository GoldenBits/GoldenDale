#pragma once

class Vertex
{
public:
	Vertex();
	Vertex(GLfloat xValue, GLfloat yValue, GLfloat zValue, GLfloat uValue, GLfloat vValue);
	GLfloat x = 0, y = 0, z = 0;
	GLfloat U = 0, V = 0;
};