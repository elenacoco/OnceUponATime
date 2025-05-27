#include "VAO.h"

VAO::VAO() {
    glGenVertexArrays(1, &id);
}

VAO::~VAO() {
    glDeleteVertexArrays(1, &id);
}

void VAO::bind() const {
    glBindVertexArray(id);
}

void VAO::unbind() const {
    glBindVertexArray(0);
}

void VAO::setAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* offset) const {
    glVertexAttribPointer(index, size, type, normalized, stride, offset);
}

void VAO::enableAttribute(GLuint index) const {
    glEnableVertexAttribArray(index);
}

GLuint VAO::getID() const {
    return id;
}
