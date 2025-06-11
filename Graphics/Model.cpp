#include"Model.h"

Model::Model(string path)
{
    loadModel(path);
}

Model::Model(string path, vector<string> pathText)
{
    pathTexture = pathText;
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
    const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenSmoothNormals | aiProcess_CalcTangentSpace);
	
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) 
    {
        cout << "ERRORE DI ASSIMP " << import.GetErrorString() << endl;
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
		if (mesh->mNormals) //controlla se ci sono normali
		{
			Vector3f vector;
			vector.x = mesh->mNormals[i].x;
			vector.y = mesh->mNormals[i].y;
			vector.z = mesh->mNormals[i].z;
			v.normal = vector;
		}
        //texture
        if (mesh->mTextureCoords[0]) //controlla solo la texture nello slot 0?
        {
            Vector2f vec;
            vec.x = mesh->mTextureCoords[0][i].x;
            vec.y = mesh->mTextureCoords[0][i].y;
            v.texCoords = vec;
            if (i < 5) // per non stampare tutto
                std::cout << "UV[" << i << "] = " << v.texCoords.x << ", " << v.texCoords.y << std::endl;

        }else
            v.texCoords = Vector2f(0.0f, 0.0f);
        //tangenti
		if (mesh->mTangents) //controlla se ci sono tangenti
		{
			Vector3f vector;
			vector.x = mesh->mTangents[i].x;
			vector.y = mesh->mTangents[i].y;
			vector.z = mesh->mTangents[i].z;
			v.tangent = vector;
		}
		//bitangenti
		if (mesh->mBitangents) //controlla se ci sono bitangenti
		{
			Vector3f vector;
			vector.x = mesh->mBitangents[i].x;
			vector.y = mesh->mBitangents[i].y;
			vector.z = mesh->mBitangents[i].z;
			v.bitangent = vector;
		}
        

        vertices.push_back(v);
		
    }

    //indici
    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++)
        {
            indices.push_back(face.mIndices[j]);
        }
    }

    textures = loadTextures(pathTexture);

	//se non ci sono texture caricate, carica una texture di default
	if (textures.empty())
	{
		Texture defaultTexture = Texture("lamp_diffuse.jpg", GL_TEXTURE_2D, 0, GL_RGB, GL_UNSIGNED_BYTE);
        std::cout << "CLASSE MODEL::Caricata Texture di Default, il suo ID: " << defaultTexture.id << std::endl;
        if (defaultTexture.id == 0) 
        {
            std::cout << "ERRORE: Texture non caricata correttamente!" << std::endl;
        }
		defaultTexture.bind(); // Bind the default texture to ensure it's ready for use
		Textures tex = { defaultTexture.id, "texture_diffuse" };
		textures.push_back(tex);
	}

    return Mesh(vertices, indices, textures);
}

//Funzione per caricare piu Texture su uno stesso modello(Diffuse, Normal, Specular, Roughness)
vector<Textures> Model::loadTextures(vector<string> path)
{
    vector<Textures> vect;

    if (path.empty())
    {
        cout << "NESSUNA TEXTURE CARICATA (PATH SBAGLIATO)"<<endl;
        return vector<Textures>();

    }
    else 
    {
        for (int i = 0; i < path.size(); i++) 
        {
            Texture tx = Texture(path[i].c_str(), GL_TEXTURE_2D, i, GL_RGB, GL_UNSIGNED_BYTE);
            tx.bind();

            //Controllo di che tipo è la texture
            if (path[i].find("diffuse") != std::string::npos)
            {
                Textures tex = { tx.id , "texture_diffuse" };
                vect.push_back(tex);
            }

            if (path[i].find("normal") != std::string::npos)
            {
                Textures tex = { tx.id , "texture_normal" };           
                vect.push_back(tex);
            }

            if (path[i].find("specular") != std::string::npos)
            {
                Textures tex = { tx.id , "texture_specular" };
                vect.push_back(tex);
            }

            if (path[i].find("roughness") != std::string::npos)
            {
                Textures tex = { tx.id , "texture_roughness" };
                vect.push_back(tex);
            }

			cout << "CLASSE MODEL::Caricata Texture: " << path[i] << ", il suo ID: " << tx.id << endl;
        }
    }
    return vect;
}

