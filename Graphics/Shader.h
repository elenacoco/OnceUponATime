#pragma once
#include "importGL.h"
#include "utils.h"

using namespace std;

class Shader
{
public:
	unsigned int shaderID;

	Shader(const string &vertexPath, const string &fragmentPath);
};