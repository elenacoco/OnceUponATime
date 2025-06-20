#include "Skybox.h"
#include "stb_image.h"

void Skybox::loadCubemap(const vector<string>& faces)
{
	glGenTextures(1, &cubemapTexture);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);

	//Parametri per la texture cubemap
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	//IMPORTANTE CHE LE IMMAGINI ABBIAMO TUTTE LA STESSA DIMENSIONE E LO STESSO FORMATO!!!!! (tipo 2048x2048 tutte e 6 le immagini)
	int width, height, nrChannels;
	for (unsigned int i = 0; i < faces.size(); i++) //scorre la dimensione dei path della texture
	{
		unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			//std::cout << "Face " << i << ": " << faces[i] << " size: " << width << "x" << height << " channels: " << nrChannels << std::endl;

			GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			stbi_image_free(data);
		}
		else
		{
			std::cout << "Cubemap texture non caricata, path: " << faces[i] << std::endl;
			std::cout << "Motivo: " << stbi_failure_reason() << std::endl;
			stbi_image_free(data);
		}
	}

	glBindTexture(GL_TEXTURE_CUBE_MAP, 0); // Unbind della texture

	//std::cout << "Cubemap caricata con ID: " << cubemapTexture << std::endl;
}

void Skybox::setupSkybox()
{
	//VAO - VBO
	// Genera e associa VAO - VBO per lo skybox
	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1, &skyboxVBO);

	// Associa VAO, associa e carica VBO
	glBindVertexArray(skyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbind VBO
	glBindVertexArray(0); // Unbind VAO
}

Skybox::Skybox()
{
}

Skybox::Skybox(const vector<string>& faces)
{
	setupSkybox();
	loadCubemap(faces);
}

Skybox::~Skybox()
{
}

void Skybox::draw(Shader& shader, Matrix4x4f view, Matrix4x4f proj, Matrix4x4f model)
{
	glDepthFunc(GL_LEQUAL); // Imposta il test di profondità per lo skybox

	shader.useProgram(); //attiva lo shader per lo skybox
	
	Matrix4x4f viewNoTranslation = view;
	viewNoTranslation.a41 = 0;
	viewNoTranslation.a42 = 0;
	viewNoTranslation.a43 = 0;
	shader.setMat4("view", viewNoTranslation); // Imposta la matrice di vista senza traslazione nello shader
	shader.setMat4("proj", proj); // Imposta la matrice di proiezione nello shader
	shader.setMat4("model", model); // Imposta la matrice del modello nello shader

	if (cubemapTexture == 0) {
		std::cout << "ERRORE: Texture della cubemap non valida!" << std::endl;
		return;
	}

	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	shader.setInt("skybox", 0); // Associa la texture dello skybox allo shader

	if (skyboxVAO == 0) {
		std::cout << "ERRORE: VAO della skybox non valido!" << std::endl;
		return;
	}

	glBindVertexArray(skyboxVAO);
	// Disegna lo skybox
	glDrawArrays(GL_TRIANGLES, 0, 36); //36 vertici per il cubo, 6 per faccia

	glBindVertexArray(0); // Unbind VAO
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0); // Unbind texture
	glDepthFunc(GL_LESS); // Reset depth function to default //CAPIRE
}

