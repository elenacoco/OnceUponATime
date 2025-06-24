#pragma once
#include <string>
#include"AlgebraLineare.h"
#include "Shader.h"
#include"importGL.h"

class Light
{
public :
	Vector3f position;
	Vector3f color;

	//costruttore
	Light(Vector3f position, Vector3f color);


	void SetUniform(Shader &shader);

};