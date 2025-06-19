#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <iostream>
#include<string>
#include<fstream>
#include<vector>

#include "Shader.h"
#include <assimp/Importer.hpp>

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_print.hpp"
//#include "rapidxml/rapidxml_iterators.hpp"
//#include "rapidxml/rapidxml_utils.hpp"

#include <AlgebraLineare.h>
#include "Model.h"
#include"Light.h"
#include "Scene.h"

//OCCHIO AI DISTRUTTORI!!!!!!

using namespace rapidxml;
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

//mettere riferimento a oggetto di classe scene per controllare la scena da lì e fare le cose in modo più ordinato
Scene* scene = nullptr;
bool isBeenPressed = false; // Indica se è stato premuto un tasto della tastiera


int main()
{
    Vector3f x_axis = Vector3f(1.0f, 0.0f, 0.0f);
    Vector3f y_axis = Vector3f(0.0f, 1.0f, 0.0f);
    Vector3f z_axis = Vector3f(0.0f, 0.0f, 1.0f);

	// glfw: initialize and configure
// ------------------------------
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
		std::cerr << "Failed to initialize scene." << std::endl;
		return -1;
	}

	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(scene->getWindowWidth(), scene->getWindowHeight(), "OnceUponATime", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}


	scene->loadFromXML("prova.xml"); // Carica la scena da un file XML


    Shader pageShader("provaPagina2.vert", "provaPagina.frag");
    //Shader shader("provaTextMulti.vert", "provaTextMulti.frag");
    //Shader shader("provaTexMultiGL.vert", "provaTexMultiGL.frag");
    Shader shader("provaPhong.vert", "provaPhong.frag");
    //Shader shader("provaVS.vert", "provaFS.frag");
	Shader skyboxShader("skybox.vert", "skybox.frag");


    //PIRAMIDE
    float vertices[] =
    { //     COORDINATES     /        COLORS      /   TexCoord  //
        -0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
        -0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
         0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
         0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
         0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f
    };

    // Indices for vertices order
    unsigned int indices[] =
    {
        0, 1, 2,
        0, 2, 3,
        0, 1, 4,
        1, 2, 4,
        2, 3, 4,
        3, 0, 4
    };

    vector<string> pathTexture1 = {"Models/Page/pagina_diffuse.jpg"};
    //vector<string> pathTexture2 = {"book_diffuse.png"};
    //Model prova = Model("Textured.obj", pathTexture1);
    //Model prova2 = Model("book_on_xz.obj", pathTexture2);
    //Model prova = Model("");
    Model prova = Model("Models/Page/pagina3.obj", pathTexture1);

	bool piramide = true;
    unsigned int VBO, VAO, EBO;


	if (!prova.meshes.empty())
	{
		std::cout << "Modello caricato con successo!" << std::endl;
		piramide = false; // Se il modello viene caricato, non disegnare la piramide
	}
	if (piramide)
	{
		std::cout << "Errore nel caricamento del modello." << std::endl;
		
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		//attributi di posizione
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		//attributi del colore
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		//attributi della texture
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		glBindVertexArray(0);
	}

	float rotation = 0.0f; // angolo di rotazione iniziale
	double lastTime = glfwGetTime(); // tempo dell'ultimo frame


	glEnable(GL_DEPTH_TEST); // abilitare il test di profondità per evitare che i poligoni vengano disegnati sopra ad altri
	glEnable(GL_CULL_FACE); // abilitare il culling per evitare di disegnare le facce interne degli oggetti
	//funziona anche per la pagina perchè ha le facce e le normali duplicate sulla parte posteriore
    


    // render loop
    // -----------
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


        //shader.useProgram(); // usa lo shader
		//
		////ROTAZIONE
		//if (currentTime - lastTime >= 1.0 / 60.0) // aggiorna ogni 1/60 di secondo
		//{
		//	rotation += 1.0f; // incrementa l'angolo di rotazione
		//	lastTime = currentTime; // aggiorna il tempo dell'ultimo frame
		//}
		//
		////PAGINA
        ////matrici per il 3d
        //Matrix4x4f modelMatrix = Matrix4x4f();
        //Matrix4x4f viewMatrix = Matrix4x4f();
        //Matrix4x4f projMatrix = Matrix4x4f();
		//
		//if (rotation >= 180.0f) // resetta la rotazione dopo un giro completo
		//{
		//	rotation = 0.0f;
		//}
		//
		//modelMatrix = modelMatrix.model(Vector3f(0.0f), Vector3f(1), -rotation, y_axis); // ruota il modello attorno all'asse y nel tempo
		//viewMatrix = viewMatrix.view(scene->getCamera().position, scene->getCamera().target, scene->getCamera().up); // aggiorna la matrice di vista con la posizione della camera
		//projMatrix = projMatrix.perspectiveSimplify(scene->getCamera().fov, (float)scene->getWindowWidth() / scene->getWindowHeight(), 0.1f, 100.0f);
		//
		//scene->updateCommonMatrices(shader, modelMatrix, viewMatrix, projMatrix); // aggiorna le matrici nel shader




		//glUniform1f(glGetUniformLocation(shaderPagina.shaderID, "time"), (float)currentTime); // Passa il tempo allo shader
		
		//glUniform1f(glGetUniformLocation(shaderPagina.shaderID, "curlRadius"), 1.0f); 
		//glUniform1f(glGetUniformLocation(shaderPagina.shaderID, "curlAmount"), 0.5f); 

		//glUniform1f(glGetUniformLocation(shaderPagina.shaderID, "flipDuration"), 2.0f);
		//glUniform1f(glGetUniformLocation(shaderPagina.shaderID, "bendAmount"), 0.5f);
		//glUniform1f(glGetUniformLocation(shaderPagina.shaderID, "pageWidth"), 16.87f); //DA CAPIRE

		if (piramide)
		{
			glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
			glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
			glBindVertexArray(0); // no need to unbind it every time 
		}

		//prova.drawModel(shader); // Draw the model


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
	if (piramide)
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}
	else
	{
		for (Mesh& mesh : prova.meshes)
		{
			mesh.VAO.unbind();
		}
	}

	delete scene; // Dealloca la scena
    glDeleteProgram(shader.shaderID);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

	//CAMBIO OGGETTI
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS && !isBeenPressed)
    {
		//premuto 1 per disegnare la primo oggetto
		std::cout << "Disegno il primo oggetto" << std::endl;
		scene->showObject(2); // Mostra il primo oggetto nella scena
		scene->isAnimationStarted = true;
		scene->isAnimationCompleted = false;
		scene->isPreviousObjectVisible = true;
		scene->isCurrentObjectVisible = false;

		isBeenPressed = true; // Imposta il flag per indicare che un tasto è stato premuto
	}
	else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS && !isBeenPressed)
	{
		//premuto 2 per disegnare il secondo oggetto
		std::cout << "Disegno il secondo oggetto" << std::endl;
		scene->showObject(3); // Mostra il secondo oggetto nella scena
		scene->isAnimationStarted = true;
		scene->isAnimationCompleted = false;
		scene->isPreviousObjectVisible = true;
		scene->isCurrentObjectVisible = false;

		isBeenPressed = true;
    }
	else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS && !isBeenPressed)
	{
		//premuto 3 per disegnare il terzo oggetto
		std::cout << "Disegno il terzo oggetto" << std::endl;
		scene->showObject(4); // Mostra il terzo oggetto nella scena
		scene->isAnimationStarted = true;
		scene->isAnimationCompleted = false;
		scene->isPreviousObjectVisible = true;
		scene->isCurrentObjectVisible = false;

		isBeenPressed = true;
	}
	else if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS && !isBeenPressed)
	{
		//premuto 4 per disegnare il quarto oggetto
		std::cout << "Disegno il quarto oggetto" << std::endl;
		scene->showObject(5); // Mostra il quarto oggetto nella scena
		scene->isAnimationStarted = true;
		scene->isAnimationCompleted = false;
		scene->isPreviousObjectVisible = true;
		scene->isCurrentObjectVisible = false;

		isBeenPressed = true;
	}
	else if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS && !isBeenPressed)
	{
		//premuto 5 per disegnare il quinto oggetto
		std::cout << "Disegno il quinto oggetto" << std::endl;
		scene->showObject(6); // Mostra il quinto oggetto nella scena
		scene->isAnimationStarted = true;
		scene->isAnimationCompleted = false;
		scene->isPreviousObjectVisible = true;
		scene->isCurrentObjectVisible = false;

		isBeenPressed = true;
	}
	else if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS && !isBeenPressed)
	{
		//premuto 6 per disegnare il sesto oggetto
		std::cout << "Disegno il sesto oggetto" << std::endl;
		scene->showObject(7); // Mostra il sesto oggetto nella scena
		scene->isAnimationStarted = true;
		scene->isAnimationCompleted = false;
		scene->isPreviousObjectVisible = true;
		scene->isCurrentObjectVisible = false;

		isBeenPressed = true;
	}
	else if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS && !isBeenPressed)
	{
		//premuto 0 per disegnare la scritta
		std::cout << "Disegno la scritta" << std::endl;
		scene->showObject(8); // Mostra il sesto oggetto nella scena
		scene->isAnimationStarted = true;
		scene->isAnimationCompleted = false;
		scene->isPreviousObjectVisible = true;
		scene->isCurrentObjectVisible = false;

		isBeenPressed = true;
	}


	//POSIZIONI CAMERA
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		//Posizione camera davanti
		cout << "Posizione camera davanti" << endl;
		scene->updateViewMatrix(scene->getCamera().position, scene->getCamera().target, scene->getCamera().up);
	}
	else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		//Posizione camera dietro
		cout << "Posizione camera dietro" << endl;
		Vector3f newPosition = scene->getCamera().position; // Sposta la camera avanti lungo l'asse Z
		newPosition.y -= scene->getCamera().position.y * 2; // Aumenta la coordinata Z per spostare la camera avanti
		//newPosition = Vector3f(0, 40, 30);
		scene->updateViewMatrix(newPosition, scene->getCamera().target, scene->getCamera().up);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		//Posizione camera a sinistra
		cout << "Posizione camera a sinistra" << endl;
		Vector3f newPosition = scene->getCamera().position; // Sposta la camera a sinistra lungo l'asse X
		newPosition.y -= scene->getCamera().position.y;
		newPosition.x -= -(scene->getCamera().position.y); // Aumenta la coordinata X per spostare la camera a sinistra
		scene->updateViewMatrix(newPosition, scene->getCamera().target, scene->getCamera().up);
	}
	else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		//Posizione camera a destra
		cout << "Posizione camera a destra" << endl;
		Vector3f newPosition = scene->getCamera().position; // Sposta la camera a destra lungo l'asse X
		newPosition.y -= scene->getCamera().position.y;
		newPosition.x += -(scene->getCamera().position.y); // Aumenta la coordinata X per spostare la camera a destra
		scene->updateViewMatrix(newPosition, scene->getCamera().target, scene->getCamera().up);
	}
	else if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
	{
		//Posizione camera in alto
		cout << "Posizione camera in alto" << endl;
		Vector3f newPosition = Vector3f(0, -0.1, 0);
		newPosition.z += scene->getCamera().position.z * 2;
		scene->updateViewMatrix(newPosition, scene->getCamera().target, scene->getCamera().up);
	}
	else if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
	{
		//Posizione camera in basso
		cout << "Posizione camera in basso" << endl;
		Vector3f newPosition = Vector3f(0, -0.1, 0);
		newPosition.z -= scene->getCamera().position.z * 2;
		scene->updateViewMatrix(newPosition, scene->getCamera().target, scene->getCamera().up);
	}

}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
