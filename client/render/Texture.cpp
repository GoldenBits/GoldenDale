#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

void Texture::setImage(std::string filePath)
{
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);

	int w, h, nrChannels;
	unsigned char* data = stbi_load(filePath.c_str(), &w, &h, &nrChannels, 4);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);
}

GLuint Texture::getID()
{
	return ID;
}
