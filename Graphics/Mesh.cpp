#include "Mesh.h"

Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures)
{
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;

	setMesh();
}

void Mesh::drawMesh(Shader& shader)
{
	unsigned int diffuseNum = 1;
	unsigned int specularNum = 1;
	unsigned int normalNum = 1;

	for (unsigned int i = 0; i < textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		string number;
		string name = textures[i].type;


	}
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
