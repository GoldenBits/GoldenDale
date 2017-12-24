#pragma once

#include <render/vertex/VertexArrayObject.h>
#include <render/vertex/buffer/VertexBufferObject.h>

class RenderData
{
public:
	void initializeData();
	VertexArrayObject & getVAO();

private:
	VertexArrayObject VAO;
};

