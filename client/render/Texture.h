#pragma once

#include <StdInc.h>
#include "string"

class Texture
{
public:
	void setImage(std::string filePath);
	GLuint getID();
private:
	GLuint ID;
};

