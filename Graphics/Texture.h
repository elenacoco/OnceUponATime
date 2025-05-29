#pragma once

#include "importGL.h"
#include "stb_image.h"
#include <iostream>

class Texture
{
public:

	GLuint id;
	GLenum type;
	GLuint unit;

	Texture(const char* image, GLenum type, GLuint unit, GLenum format, GLenum pixelType);
	~Texture();

	void bind();
	void unbind();

};