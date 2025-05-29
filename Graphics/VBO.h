#pragma once

#include "importGL.h"
#include "structs.h"
#include <vector> 


class VBO
{
private:
    GLuint id;

public:
    VBO(vector<Vertex> &vertices);
    ~VBO();

    void bind() const;
    void unbind() const;

    GLuint getID() const;
};