#pragma once
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
#include "importGL.h"
#include <iostream>
#include <string>

using namespace std;

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