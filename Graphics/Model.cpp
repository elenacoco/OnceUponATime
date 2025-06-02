#include"Model.h"

Model::Model(string path)
{
	loadModel(path);
}

void Model::drawModel(Shader& shader)
{
	for (unsigned int i = 0; i < meshes.size(); i++)
		meshes[i].drawMesh(shader);
}

void Model::loadModel(string path)
{
	Assimp::Importer import;
    const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);	
	
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) 
    {
        cout << "ERRORE DI ASSIMP" << import.GetErrorString() << endl;
        return;
    }
    directory = path.substr(0, path.find_last_of('/'));

    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode* node, const aiScene* scene)
{
    for (unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene));
    }

    for (unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene);
    }
}

Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<Textures> textures;

    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {   
        Vertex v;

        //posizione
        Vector3f vector;
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;
        v.position = vector;
        //normali
        vector.x = mesh->mNormals[i].x;
        vector.y = mesh->mNormals[i].y;
        vector.z = mesh->mNormals[i].z;
        v.normal = vector;
        //texture
        if (mesh->mTextureCoords[0]) //controlla solo la texture nello slot 0?
        {
            Vector2f vec;
            vec.x = mesh->mTextureCoords[0][i].x;
            vec.y = mesh->mTextureCoords[0][i].y;
            v.texCoords = vec;
        }
        else
            v.texCoords = Vector2f(0.0f, 0.0f);

        vertices.push_back(v);
    }

    //indici
    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; i++)
        {
            indices.push_back(face.mIndices[j]);
        }
    }

    //per ora niente materiali

    return Mesh(vertices, indices, textures);
}
