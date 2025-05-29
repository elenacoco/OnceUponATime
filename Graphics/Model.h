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

    Model(char* path);

    void drawModel(Shader& shader);

private:

    void loadModel(string path);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);
    vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);
};