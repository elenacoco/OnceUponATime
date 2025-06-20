#include "EBO.h"

EBO::EBO(const std::vector<GLuint>& indices)
{
	glGenBuffers(1, &id); //viene generato un buffer object e viene assegnato un ID unico
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id); //che tipo di buffer sto facendo e dove lo sto mettendo
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
}


EBO::~EBO()
{
    
}

void EBO::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id); //collega il buffer al target
}

void EBO::unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); //scollega il buffer dal target
}

GLuint EBO::getID() const
{
    return id;
}


