#include "VBO.h"

VBO::VBO(vector<Vertex> &vertices)
{
	glGenBuffers(1, &id);

	glBindBuffer(GL_ARRAY_BUFFER, id); //collega il buffer, array buffer è il tipo per vertex
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW); //!!!capire se è static o no
}

VBO::~VBO()
{
	glDeleteBuffers(1, &id);
}

void VBO::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

GLuint VBO::getID() const
{
	return id;
}
