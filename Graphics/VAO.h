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

    void setEnableAttribute(GLuint locationAttrib, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* offset) const;

    GLuint getID() const;
};

#endif
