#pragma once
#include <string>
#include "Mesh.h"
#include "Shader.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
 
using namespace std;
using namespace Assimp;

class Model
{
public:

    vector<Mesh> meshes;
    string directory;
    vector<string> pathTexture;

    Model(string path, vector<string> pathTex);
    Model(string path);

    void drawModel(Shader& shader, int textureIndex);

private:

    void loadModel(string path);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);
    vector<Textures> loadTextures(vector<string> path);
};