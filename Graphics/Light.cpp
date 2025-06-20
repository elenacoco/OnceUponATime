#include "Light.h"

Light::Light(string type, Vector3f direction, Vector3f color, float intensity)
{
	this->type = type;
	this->position = direction;
	this->color = color;
	this->intensity = intensity;
}

void Light::SetUniform(Shader& shader)
{
	//cosa diamo allo shader
	shader.setVec3("lightColor", color);
	shader.setVec3("lightPosition",position);
}





