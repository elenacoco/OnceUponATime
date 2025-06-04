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

//OCCHIO AI DISTRUTTORI!!!!!!

using namespace rapidxml;
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

//lo facciamo direttamente nella classe shader che chiamiamo nel main
//string vertexPath = Utils::readFile("provaVS.vert");
//const char* vertexShaderSource = vertexPath.c_str();
//
//string fragmentPath = Utils::readFile("provaFS.frag");
//const char* fragmentShaderSource = fragmentPath.c_str();



int main()
{
    //RapidXMl
    xml_document<> doc;
    xml_node<>* root_node;
    ifstream file("prova.xml");
    vector<char> buffer((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);

    root_node = doc.first_node("scene");

    int widthWindow = stoi(root_node->first_node("window")->first_node("width")->value());
    int heightWindow = stoi(root_node->first_node("window")->first_node("height")->value());

    
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(widthWindow, heightWindow, "LearnOpenGL", NULL, NULL);
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


    Shader shader("provaVS.vert", "provaFS.frag");


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


    Model prova = Model("piano.obj");
    Model prova2 = Model("cubo.obj");
    //Model prova = Model("");

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



    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    ////texture
    //unsigned int texture;
    //glGenTextures(1, &texture);
    //glBindTexture(GL_TEXTURE_2D, texture);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    ////flitri
    //int width, height, numChannels;
    //unsigned char* data = stbi_load("Lamp_bottom_Albedo.jpg", &width, &height, &numChannels, 0);
    //if (data)
    //{
    //    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data); //COLLEGA EFFETTIVAMENTE LA TEXTUREEEE, se no si vede nero
    //    glGenerateMipmap(GL_TEXTURE_2D);
    //}
    //else
    //{
    //    std::cout << "non sono riuscito a caricare la texture" << endl;
    //}
    //stbi_image_free(data);

    //Texture texture1 = Texture("Lamp_diffuse.jpg", GL_TEXTURE_2D, 0, GL_RGB, GL_UNSIGNED_BYTE); //CLASSE TEXTURE FUNZIONA
    //texture1.bind();

	float rotation = 0.0f; // angolo di rotazione iniziale
	double lastTime = glfwGetTime(); // tempo dell'ultimo frame


	glEnable(GL_DEPTH_TEST); // abilitare il test di profondità per evitare che i poligoni vengano disegnati sopra ad altri


    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //DA CAMBIARE
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        glUseProgram(shader.shaderID);

        //setta la rotazione del modello
		double currentTime = glfwGetTime(); // tempo corrente
		if (currentTime - lastTime >= 1.0 / 60.0) // aggiorna ogni 1/60 di secondo
		{
			rotation += 1.0f; // incrementa l'angolo di rotazione
			lastTime = currentTime; // aggiorna il tempo dell'ultimo frame
		}

        //per scalare il modello in base al tempo (SI RIBALTA DOPO LA SCALA A ZERO!!!!)
        float time = glfwGetTime();
        float scale = abs(sin(time)); // funzione di scala nel tempo

        //matrici per il 3d
        Matrix4x4f model = Matrix4x4f();
        model = model.model(Vector3f(0), Vector3f(1), rotation, Vector3f(0.0f, 0.0f, 1.0f));
        Matrix4x4f view = Matrix4x4f();
        //view = view.view(Vector3f(0.0f, 0.5f, -5.0f), Vector3f(0), Vector3f(0.0f, 0.5f, 0.5f)); //non mi convince
        Vector3f vec = Vector3f(0.0f, -0.7f, -15.0f);
		view = view.translate(vec); // sposto il mondo indietro di --- unità lungo l'asse z
        Matrix4x4f proj = Matrix4x4f();
        proj = proj.perspectiveSimplify(45.0f, (float)(widthWindow/heightWindow), 0.1f, 100.0f);

        glUniformMatrix4fv(glGetUniformLocation(shader.shaderID, "model"), 1, GL_TRUE, &model.a11); //BISOGNA TRASPORRE LE MATRICI!!!!!!!!!
        glUniformMatrix4fv(glGetUniformLocation(shader.shaderID, "view"), 1, GL_TRUE, &view.a11);
        glUniformMatrix4fv(glGetUniformLocation(shader.shaderID, "proj"), 1, GL_TRUE, &proj.a11);

		//cout << "Model Matrix: " << model << endl;
		//cout << "View Matrix: " << view << endl;
		//cout << "Projection Matrix: " << proj << endl;

		if (piramide)
		{
			glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
			glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
			glBindVertexArray(0); // no need to unbind it every time 
		}

		prova.drawModel(shader); // Draw the model


        Matrix4x4f model1 = Matrix4x4f();
        model1 = model1.model(Vector3f(0.0f, 4.0f, 0.0f), Vector3f(1), rotation, Vector3f(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.shaderID, "model"), 1, GL_TRUE, &model1.a11); //BISOGNA TRASPORRE LE MATRICI!!!!!!!!!

        prova2.drawModel(shader); // Draw the model



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
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}