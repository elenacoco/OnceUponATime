#include "Camera.h"

Camera::Camera()
{
	position = Vector3f(0.0f, -5.0f, 2.0f);
	target = Vector3f(0.0f, 0.0f, 0.0f);
	up = Vector3f(0.0f, 0.0f, 1.0f);
	fov = 45.0f; // FOV predefinito
}

Camera::Camera(const Vector3f& pos, const Vector3f& tar, const Vector3f& upVec, float fieldOfView)
{
	position = pos;
	target = tar;
	up = upVec;
	fov = fieldOfView;
}

Camera::Camera(const Camera& other) // Copy constructor	
{
	position = other.position;
	target = other.target;
	up = other.up;
	fov = other.fov;
}

Camera& Camera::operator=(const Camera& other)
{
	position = other.position;
	target = other.target;
	up = other.up;
	fov = other.fov;

	return *this; // Return the current object to allow chained assignments
}

void Camera::updateViewMatrix(Shader& shader, Matrix4x4f& viewMatrix)
{
	shader.setMat4("view", viewMatrix);
}
