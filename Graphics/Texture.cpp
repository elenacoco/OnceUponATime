#include "Texture.h"

Texture::Texture(const char* image, GLenum type, GLuint unit, GLenum format, GLenum pixelType)
{
	this->type = type;
	this->unit = unit;

	glGenTextures(1, &id);

	glBindTexture(type, id);

	glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT); // altri modi per wrappare la texture GL_MIRRORED_REPEAT, GL_CLAMP_TO_BORDER, GL_CLAMP_TO_EDGE
	glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT); // altri modi per wrappare la texture GL_MIRRORED_REPEAT, GL_CLAMP_TO_BORDER, GL_CLAMP_TO_EDGE

	glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //quando lo minimizzo non mi fa il filtro sfocamento
	glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //quando lo massimizzo mi usa un filtro sfocamento

	int width, height, numCh;

	unsigned char* data = stbi_load(image, &width, &height, &numCh, 0);

	if (data)
	{
		glTexImage2D(type, unit, 0, width, height, 0, format, pixelType, 0);
		glGenerateMipmap(type);
	}
	else
	{
		std::cout << "Errore nel caricamento della texture" << std::endl;
	}

	glBindTexture(type, 0);

	stbi_image_free(data);
}

Texture::~Texture()
{
	glDeleteTextures(1, &id);
}

void Texture::bind()
{
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(type, id);
}

void Texture::unbind()
{
	glBindTexture(type, 0);
}
