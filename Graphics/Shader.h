#pragma once
#include "importGL.h"
#include "utils.h"
#include "AlgebraLineare.h"

using namespace std;

class Shader
{
public:
	unsigned int shaderID;

	Shader(const string &vertexPath, const string &fragmentPath);
	~Shader();

	void useProgram();
	
	void setInt(const char* uniform, int value); //capire se è utile
	void setMat4(const char* uniform, Matrix4x4f value); //capire se è utile
};