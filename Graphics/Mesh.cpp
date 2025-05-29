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
	VAO.bind();

	VBO VBO(vertices);
	EBO EBO(indices);

	//setto e attivo tutti gli attributi dei vertici
	VAO.setEnableAttribute(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	VAO.setEnableAttribute(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	VAO.setEnableAttribute(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));
	VAO.setEnableAttribute(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
	VAO.setEnableAttribute(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, tangent));
	VAO.setEnableAttribute(5, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, bitangent));

	//scollego per evitare di modificarli involontariamente
	VBO.unbind();
	EBO.unbind();
	VAO.unbind();
}
