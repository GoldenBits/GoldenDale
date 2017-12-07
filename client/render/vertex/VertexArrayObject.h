#pragma once

class VertexArrayObject {
public:
	VertexArrayObject();
    void bindVertexArray();
    void vertexAttributeConfiguration();
    void unbind();
private:
	GLuint ID;
	void genVertexArray();

	void enableAttribureArray(GLuint index);
};


