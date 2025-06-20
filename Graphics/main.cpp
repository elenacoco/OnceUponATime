#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include<fstream>
#include <assimp/Importer.hpp>

#include "Scene.h"

using namespace rapidxml;
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void showObject(int objectIndex);

Scene* scene = nullptr; //puntatore alla scena
bool isBeenPressed = false; // Indica se è stato premuto un tasto della tastiera per l'animazione della pagina


int main()
{

	//Inizializziamo glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	scene = new Scene(800, 800); // Crea un'istanza della scena con dimensioni predefinite
	scene->initialize("prova.xml"); // Inizializza la scena

	if (scene == nullptr) {
		std::cerr << "Non ho trovato nessuna scena da inizializzare" << std::endl;
		return -1;
	}

	//creazione dela finestra glfw
	GLFWwindow* window = glfwCreateWindow(scene->getWindowWidth(), scene->getWindowHeight(), "OnceUponATime", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Non ho trovato nessuna finestra GLFW da creare" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//Carichiamo glad e tutte le funzioni OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) //dopo aver costruito il contesto OpenGL
	{
		std::cout << "Non sono riuscito a inizalizzare GLAD" << std::endl;
		return -1;
	}


	scene->loadFromXML("prova.xml"); // Carica la scena da un file XML


    Shader pageShader("provaPagina.vert", "provaPagina.frag"); //shader per la pagina
    Shader shader("provaPhong.vert", "provaPhong.frag"); //shader per tutti i modelli
	Shader skyboxShader("skybox.vert", "skybox.frag"); //shader per lo skybox


	glEnable(GL_DEPTH_TEST); // abilitare il test di profondità per evitare che i poligoni vengano disegnati sopra ad altri
	glEnable(GL_CULL_FACE); // abilitare il culling per evitare di disegnare le facce interne degli oggetti
	//funziona anche per la pagina perchè ha le facce e le normali duplicate sulla parte posteriore
    


    // render loop
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

		if (scene->isAnimationCompleted)
		{
			isBeenPressed = false; // Resetta il flag quando l'animazione è completata
		}

		double currentTime = glfwGetTime(); // tempo corrente
		scene->update(currentTime);

		scene->render(shader, skyboxShader, pageShader);

        // Swap buffer e reagisce agli eventi (tipo tasti tastiera premuti)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

	delete scene; // Dealloca la scena
    glDeleteProgram(shader.shaderID);

    // termina e ripulisce tutte le risorse allocate da glfw
    glfwTerminate();
    return 0;
}


void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

	//CAMBIO OGGETTI
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS && !isBeenPressed)
    {
		//premuto 1 per disegnare la primo oggetto
		std::cout << "Disegno il primo oggetto" << std::endl;
		scene->bookTextureIndexToSet = 1;
		scene->pageFrontTextureIndex = 2; //pari per tutti i pageFront...
		scene->pageBackTextureIndex = 3; //dispari per tutti i pageBack...
		showObject(2); //il primo oggetto è 2 perchè il modello 0 è il libro e il modello 1 la pagina
	}
	else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS && !isBeenPressed)
	{
		//premuto 2 per disegnare il secondo oggetto
		std::cout << "Disegno il secondo oggetto" << std::endl;
		scene->bookTextureIndexToSet = 2;
		scene->pageFrontTextureIndex = 4;
		scene->pageBackTextureIndex = 5;
		showObject(3);
    }
	else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS && !isBeenPressed)
	{
		//premuto 3 per disegnare il terzo oggetto
		std::cout << "Disegno il terzo oggetto" << std::endl;
		scene->bookTextureIndexToSet = 3;
		scene->pageFrontTextureIndex = 6;
		scene->pageBackTextureIndex = 7;
		showObject(4);
	}
	else if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS && !isBeenPressed)
	{
		//premuto 4 per disegnare il quarto oggetto
		std::cout << "Disegno il quarto oggetto" << std::endl;
		scene->bookTextureIndexToSet = 4;
		scene->pageFrontTextureIndex = 8;
		scene->pageBackTextureIndex = 9;
		showObject(5);
	}
	else if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS && !isBeenPressed)
	{
		//premuto 5 per disegnare il quinto oggetto
		std::cout << "Disegno il quinto oggetto" << std::endl;
		scene->bookTextureIndexToSet = 5;
		scene->pageFrontTextureIndex = 10;
		scene->pageBackTextureIndex = 11;
		showObject(6);
	}
	else if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS && !isBeenPressed)
	{
		//premuto 6 per disegnare il sesto oggetto
		std::cout << "Disegno il sesto oggetto" << std::endl;
		scene->bookTextureIndexToSet = 6;
		scene->pageFrontTextureIndex = 12;
		scene->pageBackTextureIndex = 13;
		showObject(7);
	}
	else if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS && !isBeenPressed)
	{
		//premuto 7 per disegnare il settimo oggetto
		std::cout << "Disegno il settimo oggetto" << std::endl;
		scene->bookTextureIndexToSet = 7;
		scene->pageFrontTextureIndex = 14;
		scene->pageBackTextureIndex = 15;
		showObject(8);
	}
	else if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS && !isBeenPressed)
	{
		//premuto 8 per disegnare il ottavo oggetto
		std::cout << "Disegno il ottavo oggetto" << std::endl;
		scene->bookTextureIndexToSet = 8;
		scene->pageFrontTextureIndex = 16;
		scene->pageBackTextureIndex = 17;
		showObject(9);
	}
	else if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS && !isBeenPressed)
	{
		//premuto 9 per disegnare il nono oggetto
		std::cout << "Disegno il nono oggetto" << std::endl;
		scene->bookTextureIndexToSet = 9;
		scene->pageFrontTextureIndex = 18;
		scene->pageBackTextureIndex = 19;
		showObject(10);
	}
	else if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS && !isBeenPressed)
	{
		//premuto 0 per disegnare la scritta
		std::cout << "Disegno la scritta" << std::endl;
		scene->bookTextureIndexToSet = 0;
		scene->pageFrontTextureIndex = 0;
		scene->pageBackTextureIndex = 1;
		showObject(11);
	}


	//POSIZIONI CAMERA
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS && !scene->isCameraMoving)
	{
		//Posizione camera davanti
		cout << "Posizione camera davanti" << endl;
		scene->startCameraMove(scene->getCamera().position);
	}
	else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && !scene->isCameraMoving)
	{
		//Posizione camera dietro
		cout << "Posizione camera dietro" << endl;
		Vector3f newPosition = scene->getCamera().position; // Sposta la camera avanti lungo l'asse Y
		newPosition.y -= scene->getCamera().position.y * 2; // Aumenta la coordinata Y per spostare la camera avanti
		scene->startCameraMove(newPosition);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS && !scene->isCameraMoving)
	{
		//Posizione camera a sinistra
		cout << "Posizione camera a sinistra" << endl;
		Vector3f newPosition = scene->getCamera().position; // Sposta la camera a sinistra lungo l'asse X
		newPosition.y -= scene->getCamera().position.y;
		newPosition.x -= -(scene->getCamera().position.y); // Aumenta la coordinata X per spostare la camera a sinistra
		scene->startCameraMove(newPosition);
	}
	else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && !scene->isCameraMoving)
	{
		//Posizione camera a destra
		cout << "Posizione camera a destra" << endl;
		Vector3f newPosition = scene->getCamera().position; // Sposta la camera a destra lungo l'asse X
		newPosition.y -= scene->getCamera().position.y;
		newPosition.x += -(scene->getCamera().position.y); // Aumenta la coordinata X per spostare la camera a destra
		scene->startCameraMove(newPosition);
	}
	else if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS && !scene->isCameraMoving)
	{
		//Posizione camera in alto
		cout << "Posizione camera in alto" << endl;
		Vector3f newPosition = Vector3f(0, -0.1, 0); //y non è 0 perchè se no la norma è zero
		newPosition.z += scene->getCamera().position.z * 2;
		scene->startCameraMove(newPosition);
	}
	else if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS && !scene->isCameraMoving)
	{
		//Posizione camera in basso
		cout << "Posizione camera in basso" << endl;
		Vector3f newPosition = Vector3f(0, -0.1, 0);
		newPosition.z -= scene->getCamera().position.z * 2;
		scene->startCameraMove(newPosition);
	}

}

void showObject(int objectIndex)
{
	scene->showObject(objectIndex);
	scene->isAnimationStarted = true;
	scene->isAnimationCompleted = false;
	scene->isPreviousObjectVisible = true;
	scene->isCurrentObjectVisible = false;

	isBeenPressed = true;
}

// Quando la finestra viene ridimensionata viene chiamata questa funzione
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
