#include "VAO.h"

VAO::VAO() {
    glGenVertexArrays(1, &id); //"a questo id ci sarà un vertex array"
}

VAO::~VAO() 
{
}

void VAO::unbind() const {
    glBindVertexArray(0);
}

void VAO::setEnableAttribute(GLuint locationAttrib, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* offset) const 
{
    glVertexAttribPointer(locationAttrib, size, type, normalized, stride, offset);
    glEnableVertexAttribArray(locationAttrib);
}


GLuint VAO::getID() const {
    return id;
}
