#pragma once
#include <string>
#include"AlgebraLineare.h"
#include "Shader.h"
#include"importGL.h"

class Light
{
public :
	string type;
	Vector3f position;
	Vector3f color;
	float intensity;

	Light(string type, Vector3f direction, Vector3f color, float intensity);


	void SetUniform(Shader &shader);

};