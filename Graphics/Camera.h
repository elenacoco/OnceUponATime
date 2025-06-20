#pragma once

#include "AlgebraLineare.h"
#include "Shader.h"

class Camera
{
public:
	Vector3f position;
	Vector3f target;
	Vector3f up;
	float fov; //in gradi

	Camera(); // Default constructor (mette tutto a 0)
	Camera(const Vector3f& pos, const Vector3f& tar, const Vector3f& upVec, float fieldOfView);
	Camera(const Camera& other); // Copy constructor

	Camera& operator=(const Camera& other); // Copy assignment operator

	void updateViewMatrix(Shader& shader, Matrix4x4f& viewMatrix);
	
};
