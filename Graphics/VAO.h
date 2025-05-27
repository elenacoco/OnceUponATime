#ifndef VAO_H
#define VAO_H

#include <glad/glad.h>

class VAO {
private:
    GLuint id;

public:
    VAO();
    ~VAO();

    void bind() const;
    void unbind() const;

    void setAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* offset) const;
    void enableAttribute(GLuint index) const;

    GLuint getID() const;
};

#endif
