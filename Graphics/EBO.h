#pragma once
//ELEMENT BUFFER OBJECT

#include <vector>
#include <glad/glad.h>

class EBO
{
private:
    GLuint id;

public:
    EBO(const std::vector<GLuint>& indices);
    ~EBO();

    void bind() const;
    void unbind() const;

    GLuint getID() const;
};


