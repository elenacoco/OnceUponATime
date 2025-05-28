#pragma once

#include <vector>
#include "Vertex.h"
#include "Shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

using namespace std;

class Mesh
{
public:

	//dati della mesh
	
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	//vector<Texture> textures;
	unsigned int VAO; //così posso utilizzarla nel draw

	//costruttore
	Mesh(vector<Vertex> vertices, vector<unsigned int> indices);

	//disegno le mesh
	void drawMesh(Shader &shader);

private:

	//setup delle mesh
	void setMesh();
};
