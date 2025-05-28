#pragma once

#include <vector>
#include "Vertex.h"
#include "Shader.h"

using namespace std;

class Mesh
{
public:

	//dati della mesh
	
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	//vector<Texture> textures;

	// Constructor
	Mesh(vector<float> vertices, vector<unsigned int> indices);

	//disegno le mesh
	void Draw(Shader &shader);

private:

	//dati per il rendering
	unsigned int VAO, VBO, EBO;

	//setup delle mesh
	void setMesh();
};
