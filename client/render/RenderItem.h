#pragma once


#include <render/shader/shader.h>
#include <render/shader/ShaderProgram.h>
#include "RenderData.h"
#include "vertex/Vertex.h"

class RenderItem
{
public:
	ShaderProgram * getShaderProgram();
	void setShaderProgram(ShaderProgram * program);
	void setData();
	RenderData getData();
	void enable(bool on);
	bool isEnabled();

protected:
private:
	bool enabled = true;
	ShaderProgram * shaderProgram;
	RenderData data;
};

