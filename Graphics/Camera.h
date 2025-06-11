#pragma once

#include "AlgebraLineare.h"

class Camera
{
public:
	Vector3f position;
	Vector3f target;
	Vector3f up;
	float fov;

	Camera(); // Default constructor
	Camera(const Vector3f& pos, const Vector3f& tar, const Vector3f& upVec, float fieldOfView);
	Camera(const Camera& other); // Copy constructor

	Camera& operator=(const Camera& other); // Copy assignment operator

	Matrix4x4f updateViewMatrix(Matrix4x4f& viewMatrix);
	
};
