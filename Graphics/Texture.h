#pragma once

#include "importGL.h"
#include "stb_image.h"
#include <iostream>
#include <string>

class Texture
{
public:

	GLuint id;
	GLenum type;
	GLuint unit;
	string name;

	Texture(string name, const char* image, GLenum type, GLuint unit, GLenum format, GLenum pixelType);
	~Texture();

	void bind();
	void unbind();

};