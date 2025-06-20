#include "Mesh.h"

Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Textures> textures)
{
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;

	setMesh();
}

void Mesh::drawMesh(Shader& shader) //non più usato 
{
	unsigned int diffuseNum = 1;
	unsigned int specularNum = 1;
	unsigned int normalNum = 1;

	for (unsigned int i = 0; i < textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);

		string number;
		string name = textures[i].name;

		if (name == "texture_diffuse")
		{
			number = to_string(diffuseNum++);
		}
		else if (name == "texture_specular")
		{
			number = to_string(specularNum++);
		}
		else if (name == "texture_normal")
		{
			number = to_string(normalNum++);
		}

		shader.setInt((name + number).c_str(), i); //passa il nome della uniform e il valore da assegnare
		glBindTexture(GL_TEXTURE_2D, textures[i].id); //bind della texture all'id giusto
	}

	glActiveTexture(GL_TEXTURE0); 

	VAO.bind();
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0); //disegna ciò che vediamo (0 location)
	VAO.unbind();
}


void Mesh::drawMesh(Shader& shader, int textureIndex)
{
	if (textureIndex < textures.size())
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textures[textureIndex].id);
		shader.setInt("texture_diffuse1", 0);
	}
	else
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textures[0].id);
		shader.setInt("texture_diffuse1", 0);
	}

	glActiveTexture(GL_TEXTURE0);

	VAO.bind();
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	VAO.unbind();
}

void Mesh::setMesh()
{
	VAO.bind();

	VBO VBO(vertices); //VBO con i vertici
	EBO EBO(indices); //EBO con gli indici

	//setto e attivo tutti gli attributi dei vertici
	VAO.setEnableAttribute(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	VAO.setEnableAttribute(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	VAO.setEnableAttribute(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));
	VAO.setEnableAttribute(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
	VAO.setEnableAttribute(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, tangent));
	VAO.setEnableAttribute(5, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, bitangent));

	//scollego per evitare di modificarli involontariamente
	VBO.unbind();
	VAO.unbind();
}
