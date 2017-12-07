#include "RenderItem.h"

void RenderItem::enable(bool on)
{
	enabled = on;
}

bool RenderItem::isEnabled()
{
	return enabled;
}

ShaderProgram *RenderItem::getShaderProgram()
{
	return shaderProgram;
}

void RenderItem::setShaderProgram(ShaderProgram *program)
{
	shaderProgram = program;
}

void RenderItem::setData()
{
	data.initializeData();
}

RenderData RenderItem::getData()
{
	return data;
}