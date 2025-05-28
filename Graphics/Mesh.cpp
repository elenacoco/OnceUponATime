#include "Mesh.h"

Mesh::Mesh(vector<float> vertices, vector<unsigned int> indices)
{
	this->vertices = vertices;
	this->indices = indices;

	setMesh();
}

void Mesh::setMesh()
{

}
