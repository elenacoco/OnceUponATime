#include "Camera.h"

Camera::Camera(const Vector3f& pos, const Vector3f& tar, const Vector3f& upVec, float fieldOfView)
{
	position = pos;
	target = tar;
	up = upVec;
	fov = fieldOfView;
}

Matrix4x4f Camera::updateViewMatrix(Matrix4x4f& viewMatrix)
{
	return viewMatrix.view(position, target, up);
}
