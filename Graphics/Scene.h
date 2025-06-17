#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "importGL.h"
#include "Model.h"
#include "Shader.h"
#include "Light.h"
#include "AlgebraLineare.h"
#include "Camera.h"
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_print.hpp"

using namespace std;
using namespace rapidxml;


class Scene {

private:

	//parametri di scena
	vector<Model> models;
	vector<Light> lights;
	Camera camera;

	//matrici
	Matrix4x4f modelMatrix;
	Matrix4x4f viewMatrix;
	Matrix4x4f projMatrix;

	//parametri della finestra
	int widthWindow;
	int heightWindow;

	//colori e illuminazione
	Vector3f backgroundColor;
	Vector3f ambientLight;

	//controllo visualizzazione
	int currentVisibileObjectIndex; //indice dell'oggetto attualmente visibile
	int indexSelected;

	//parametri di animazione
	float rotation; // velocità di rotazione degli oggetti
	float scaleModel; // scala del modello
	double lastTime; // tempo dell'ultimo frame per l'animazione
	//qualcosa per la pagina
	float rotationPage;

public:

	bool isAnimationCompleted = false; // Indica se l'animazione totale è completata
	bool isAnimationStarted = false; // Indica se è stata premuta un qualsiasi tasto della tastiera
	bool isCurrentObjectVisible = true; // Indica se l'oggetto attualmente visibile è visibile
	bool isPreviousObjectVisible = true; // Indica se l'oggetto attualmente visibile è visibile
	bool isPageAnimationStarted = false; // Indica se la pagina è stata girata
	bool isPageAnimationEnded = false; // Indica se la pagina è stata girata

	//costruttore
	Scene(int width, int height);
	//distruttore
	~Scene();

	//Inizializza la dimensione della finestra
	void initialize(const string& nameXML);
	//Va messo dopo glfw e glad (perché usa le loro funzioni e dobbiamo prima inizializzare il contesto openGL)
	void loadFromXML(const string& nameXML); 

	//gestione modelli
	void addModel(const Model& model); // aggiunge un modello alla scena
	void addModel(const string& modelPath, const vector<string> texturePath);

	// gestione luci
	void addLight(const Light& light); // aggiunge una luce alla scena

	//gestione della camera
	void setCamera(const Vector3f& position, const Vector3f& target, const Vector3f& up, float fov);
	Camera& getCamera() { return camera; } 

	//gestione colori e illuminazione
	void setBackgroundColor(const Vector3f& color);
	void setAmbientLight(const Vector3f& color);

	//rendering
	void render(Shader& shader);
	void update(float currentTime);

	//controllo visualizzazione oggetti
	void showObject(int index); // mostra l'oggetto con l'indice specificato //DA FINIRE
	void changeObject(int index); // cambia l'oggetto attualmente visibile con quello con l'indice specificato
	void hideObject(int index); // nasconde l'oggetto con l'indice specificato

	//input
	void processInput(GLFWwindow* window);

	//utility
	int getModelCount() const { return models.size(); }
	bool isObjectVisible(int index) const;
	void updateCommonMatrices(Shader& shader, const Matrix4x4f& model, const Matrix4x4f& view, const Matrix4x4f& proj);
	void updateViewMatrix(Vector3f position, Vector3f target, Vector3f up);
	Matrix4x4f getModelMatrix() const { return modelMatrix; }
	Matrix4x4f getViewMatrix() const { return viewMatrix; }
	Matrix4x4f getProjMatrix() const { return projMatrix; }

	// Getters
	Vector3f getBackgroundColor() const { return backgroundColor; }
	Vector3f getAmbientLight() const { return ambientLight; }
	int getWindowWidth() const { return widthWindow; }
	int getWindowHeight() const { return heightWindow; }
};
