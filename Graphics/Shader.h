#pragma once
#include "importGL.h"
#include "utils.cpp"

using namespace std;

class Shader
{
public:
	unsigned int shaderID;

	Shader(const string &vertexPath, const string &fragmentPath);
};