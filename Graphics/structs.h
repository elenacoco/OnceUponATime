#pragma once
#include <AlgebraLineare.h>
#include <string>

using namespace std;

struct Vertex
{
	Vector3f position; //location 0
	Vector3f color;  //location 1
	Vector2f texCoords; //location 2
	Vector3f normal;  //location 3
	Vector3f tangent; //location 4
	Vector3f bitangent;  //location 5 

};

struct Textures
{
	unsigned int id;
	string name;
};