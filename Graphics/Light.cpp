#include "Light.h"

Light::Light(Vector3f position, Vector3f color)
{
	this->position = position;
	this->color = color;
}

void Light::SetUniform(Shader& shader)
{
	//cosa diamo allo shader
	shader.setVec3("lightColor", color);
	shader.setVec3("lightPosition",position);
}





