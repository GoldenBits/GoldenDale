#include "StdInc.h"
#include "vertex/Vertex.h"
#include "RenderData.h"

void RenderData::initializeData()
{
	VertexBufferObject VBO;
	std::vector<Vertex> vertices = {{0.0f, 1.0f, 0.0f, 0.0f, 1.0f},
									{1.0f, 0.0f, 0.0f, 1.0f, 0.0f},
									{0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
									{0.0f, 1.0f, 0.0f, 0.0f, 1.0f},
									{1.0f, 1.0f, 0.0f, 1.0f, 1.0f},
									{1.0f, 0.0f, 0.0f, 1.0f, 0.0f}};
	VBO.setVertices(vertices);

	VBO.genBuffer();
	VBO.bind();
	VBO.bufferData();
	VAO.bindVertexArray();
	VAO.vertexAttributeConfiguration();

	VBO.unbind();
	VAO.unbind();
}

VertexArrayObject &RenderData::getVAO()
{
	return VAO;
}
