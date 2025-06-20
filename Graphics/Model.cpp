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

void Model::drawModel(Shader& shader, int textureIndex)
{
	for (unsigned int i = 0; i < meshes.size(); i++)
		meshes[i].drawMesh(shader, textureIndex);
}

void Model::loadModel(string path)
{
	Assimp::Importer import; //carica l'importer di assimp
    const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenSmoothNormals | aiProcess_CalcTangentSpace);
	//triangola le mesh, flippa gli UV lungo l'asse y, genera le normali ai vertici, calcola tangenti e bitangenti
	
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) 
    {
        cout << "ERRORE DI ASSIMP " << import.GetErrorString() << endl;
        return;
    }
    directory = path.substr(0, path.find_last_of('/')); //fa una substring da 0 fino allo / finale

	processNode(scene->mRootNode, scene); //processa il nodo radice della scena
}

void Model::processNode(aiNode* node, const aiScene* scene)
{
    for (unsigned int i = 0; i < node->mNumMeshes; i++) //dal nodo radice prendiamo il numero delle mesh
    {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]]; //prendo la mesh i-esima
		meshes.push_back(processMesh(mesh, scene)); //nel vectore di meshes aggiungo la mesh i-esima processata
    }

    for (unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene); //chiama processNode per tutti gli altri figli (metodo iterativo)
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
		if (mesh->mNormals) //controlla se la mesh ha delle normali
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
        

		vertices.push_back(v); //aggiungo il vertice al vector di vertex
		
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

	//se non ci sono texture caricate, stampa un messaggio
	if (textures.empty())
	{
        std::cout << "CLASSE MODEL::Nessuna texture caricata " << std::endl;
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
            Texture tx = Texture(path[i].c_str(), GL_TEXTURE_2D, 0, GL_RGB, GL_UNSIGNED_BYTE); //lo 0 indica la unit (ci serve solo quella)
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

			//cout << "CLASSE MODEL::Caricata Texture: " << path[i] << ", il suo ID: " << tx.id << endl;
        }
    }
    return vect;
}

