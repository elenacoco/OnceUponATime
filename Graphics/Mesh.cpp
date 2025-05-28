#include "Mesh.h"

Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices)
{
	this->vertices = vertices;
	this->indices = indices;
	//texture da aggiungere

	setMesh();
}

void Mesh::drawMesh(Shader& shader)
{
	//da capire
}

void Mesh::setMesh()
{
	//non posso usare le funzioni del vao, forse perchè sono costanti?
}
