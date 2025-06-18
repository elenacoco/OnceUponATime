#include "Scene.h"

Scene::Scene(int width, int height)
{
	widthWindow = width;
	heightWindow = height;
	camera = Camera();
	skybox = Skybox(); // Inizializza lo skybox

	currentVisibileObjectIndex = 2; // Inizialmente nessun oggetto visibile
	rotation = 0.01f; // Velocità di rotazione predefinita
	backgroundColor = Vector3f(0.2f, 0.3f, 0.3f); // Colore di sfondo predefinito
	ambientLight = Vector3f(1.0f, 1.0f, 1.0f); // Colore della luce ambientale predefinito

    modelMatrix = Matrix4x4f();
    viewMatrix = Matrix4x4f();
    projMatrix = Matrix4x4f();

	currentTimePage = 0.0f; // Inizializza il tempo corrente della pagina
	previousTimePage = 0.0f; // Inizializza il tempo precedente della pagina
}

Scene::~Scene()
{
}

void Scene::initialize(const string& nameXML)
{
    lastTime = glfwGetTime(); // Inizializza il tempo dell'ultimo frame per l'animazione
	scaleModel = 1.0f; // Inizializza la scala del modello a 1.0f

    //RapidXMl
    xml_document<> doc;
    xml_node<>* root_node;
    ifstream file(nameXML);
    vector<char> buffer((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);

    root_node = doc.first_node("scene");

    //Finestra
    widthWindow = stoi(root_node->first_node("window")->first_node("width")->value());
    heightWindow = stoi(root_node->first_node("window")->first_node("height")->value());
}

void Scene::loadFromXML(const string& nameXML)
{
    //RapidXMl
    xml_document<> doc;
    xml_node<>* root_node;
    ifstream file(nameXML);
    vector<char> buffer((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);

	root_node = doc.first_node("scene");

    // Ambiente
    xml_node<>* env = root_node->first_node("environment");
    xml_node<>* bg = env->first_node("backgroundColor");
    backgroundColor = Vector3f(stof(bg->first_attribute("r")->value()), stof(bg->first_attribute("g")->value()), stof(bg->first_attribute("b")->value()));
    cout << "Colore di sfondo: " << backgroundColor << endl;

    xml_node<>* ambient = env->first_node("ambientLight");
    ambientLight = Vector3f(stof(ambient->first_attribute("r")->value()), stof(ambient->first_attribute("g")->value()), stof(ambient->first_attribute("b")->value()));
    cout << "Colore della luce ambientale: " << ambientLight << endl;


    //Skybox
	xml_node<>* skyboxNode = root_node->first_node("skybox");
	vector<string> skyboxFaces;
	for (xml_node<>* faceNode = skyboxNode->first_node("face"); faceNode; faceNode = faceNode->next_sibling("face"))
	{
		string facePath = faceNode->value();
		cout << "Skybox face path: " << facePath << endl;
		skyboxFaces.push_back(facePath);
	}
	skybox = Skybox(skyboxFaces); // Crea lo skybox con i percorsi delle facce


    //Luci
    xml_node<>* lightsNode = root_node->first_node("lights");

    for (xml_node<>* lightNode = lightsNode->first_node("light"); lightNode; lightNode = lightNode->next_sibling("light"))
    {
        string lightType = lightNode->first_node("type")->value();
        cout << "light type" << lightType << endl;
        Vector3f position = Vector3f(stof(lightNode->first_node("position")->first_attribute("x")->value()),
            stof(lightNode->first_node("position")->first_attribute("y")->value()),
            stof(lightNode->first_node("position")->first_attribute("z")->value()));
        cout << "position luce" << position << endl;
        Vector3f color = Vector3f(stof(lightNode->first_node("color")->first_attribute("r")->value()),
            stof(lightNode->first_node("color")->first_attribute("g")->value()),
            stof(lightNode->first_node("color")->first_attribute("b")->value()));
        cout << "colore luce" << color << endl;
        float intensity = stof(lightNode->first_node("intensity")->value());
        Light light = Light(lightType, position, color, intensity);
        lights.push_back(light);
    }

    //Camera
    xml_node<>* cameraNode = root_node->first_node("camera");

    Vector3f cameraPos = Vector3f(stof(cameraNode->first_node("position")->first_attribute("x")->value()),
        stof(cameraNode->first_node("position")->first_attribute("y")->value()),
        stof(cameraNode->first_node("position")->first_attribute("z")->value()));
    cout << "Camera position: " << cameraPos << endl;

    Vector3f cameraTarget = Vector3f(stof(cameraNode->first_node("target")->first_attribute("x")->value()),
        stof(cameraNode->first_node("target")->first_attribute("y")->value()),
        stof(cameraNode->first_node("target")->first_attribute("z")->value()));
    cout << "Camera target: " << cameraTarget << endl;

    Vector3f cameraUp = Vector3f(stof(cameraNode->first_node("up")->first_attribute("x")->value()),
        stof(cameraNode->first_node("up")->first_attribute("y")->value()),
        stof(cameraNode->first_node("up")->first_attribute("z")->value()));
    cout << "Camera up: " << cameraUp << endl;

    float fov = stof(cameraNode->first_node("fov")->value());
    cout << "Camera FOV: " << fov << endl;
    camera = Camera(cameraPos, cameraTarget, cameraUp, fov); // Imposta la camera con i valori letti dal file XML

	float nearPlane = stof(cameraNode->first_node("nearPlane")->value());
	float farPlane = stof(cameraNode->first_node("farPlane")->value());


    //Modelli
    xml_node<>* modelsNode = root_node->first_node("models");

    for (xml_node<>* modelNode = modelsNode->first_node("model"); modelNode; modelNode = modelNode->next_sibling("model"))
    {
        //non legge il nome del modello, serve?
        string modelPath = modelNode->first_node("path")->value();
        cout << "Model path: " << modelPath << endl; // Stampa il percorso del modello
        vector<string> texturePaths;
        xml_node<>* texturesNode = modelNode->first_node("textures");
        for (xml_node<>* textureNode = texturesNode->first_node("texture"); textureNode; textureNode = textureNode->next_sibling("texture"))
        {
            texturePaths.push_back(textureNode->value());
            cout << "Texture path: " << textureNode->value() << endl; // Stampa il percorso della texture
            //non legge il type della texture, serve?
        }
        Model model(modelPath, texturePaths); //DA PROBLEMI MA NON CAPISCO PERCHE', non entra nemmeno nell'if sotto, crasha prima
        if (!model.meshes.empty())
        {
            cout << "Modello caricato con successo: " << modelPath << endl;
            models.push_back(model);
        }
        else
        {
            cout << "Errore nel caricamento del modello: " << modelPath << endl;
            return; // Esci se un modello non viene caricato correttamente
        }
        //manca la lettura del transform
    }

    updateViewMatrix(camera.position, camera.target, camera.up);
    projMatrix = projMatrix.perspectiveSimplify(camera.fov, (float)widthWindow / heightWindow, nearPlane, farPlane);
}

void Scene::addModel(const Model& model)
{
	models.push_back(model); // Aggiunge un modello alla scena
}

void Scene::addModel(const string& modelPath, const vector<string> texturePath)
{
    Model model(modelPath, texturePath); // Crea un modello con il percorso specificato e la texture
	if (!model.meshes.empty())
	{
		models.push_back(model); // Aggiunge il modello alla scena se è stato caricato correttamente
	}
	else
	{
		std::cout << "Errore nel caricamento del modello: " << modelPath << std::endl;
	}
}

void Scene::addLight(const Light& light)
{
	lights.push_back(light); // Aggiunge una luce alla scena
}

void Scene::setCamera(const Vector3f& position, const Vector3f& target, const Vector3f& up, float fov)
{
	camera = Camera(position, target, up, fov); // Imposta la camera con i valori specificati
}

void Scene::setBackgroundColor(const Vector3f& color)
{
	backgroundColor = color; // Imposta il colore di sfondo della scena
}

void Scene::setAmbientLight(const Vector3f& color)
{
	ambientLight = color; // Imposta il colore della luce ambientale della scena
}

void Scene::render(Shader& shader, Shader& skyboxShader, Shader& pageShader)
{
    //imposta il colore di sfondo
    glClearColor(backgroundColor.x, backgroundColor.y, backgroundColor.z, 1.0f);
    //DA CAPIRE
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader.useProgram(); // usa lo shader
    
    Vector3f x_axis = Vector3f(1.0f, 0.0f, 0.0f);
    Vector3f y_axis = Vector3f(0.0f, 1.0f, 0.0f);
    Vector3f z_axis = Vector3f(0.0f, 0.0f, 1.0f);
    
	//LIBRO
	modelMatrix = Matrix4x4f();
	updateCommonMatrices(shader, modelMatrix, viewMatrix, projMatrix); // aggiorna le matrici nel shader
    models[0].drawModel(shader); // Disegna il primo modello sempre perchè è il libro
    
	//OGGETTO
	modelMatrix = Matrix4x4f();
	Vector3f translate = Vector3f(0.0f, 0.0f, 10.0f); // posizione dell'oggetto
	Vector3f scale = Vector3f(scaleModel); // scala dell'oggetto
	modelMatrix = modelMatrix.model(translate, scale, rotation, z_axis); // ruota il modello attorno all'asse z nel tempo
	shader.setMat4("model", modelMatrix); // Imposta la matrice del modello nello shader
    models[currentVisibileObjectIndex].drawModel(shader); // Disegna il modello attualmente visibile
    
    //setta le uniform per gli shader che hanno una luce (PHONG)
    lights[0].SetUniform(shader);
    shader.setVec3("viewPosition", camera.position);
    shader.setVec3("ambientLight", ambientLight);
    
    //shader Piu' Texture
	shader.setVec3("lightPosition", lights[0].position); // Imposta la posizione della vista nello shader
	shader.setVec3("lightColor", lights[0].color); // Imposta il colore della luce nello shader


    if (isPageAnimationStarted)
    {
        //PAGINA
        pageShader.useProgram(); // usa lo shader della pagina

        modelMatrix = Matrix4x4f();
        modelMatrix = modelMatrix.model(Vector3f(0.0f), Vector3f(1.0f), -rotationPage, y_axis); // ruota il modello attorno all'asse y nel tempo
        updateCommonMatrices(pageShader, modelMatrix, viewMatrix, projMatrix); // aggiorna le matrici nel shader

        double currentTime = glfwGetTime(); // tempo corrente
		currentTimePage += currentTime - previousTimePage; // Aggiorna il tempo corrente della pagina
        glUniform1f(glGetUniformLocation(pageShader.shaderID, "time"), currentTimePage);
        glUniform1f(glGetUniformLocation(pageShader.shaderID, "curlAmplitude"), 3.0f);
        glUniform1f(glGetUniformLocation(pageShader.shaderID, "curlAmount"), 0.2f);
        glUniform1f(glGetUniformLocation(pageShader.shaderID, "animationSpeed"), 1.5f);

        lights[0].SetUniform(pageShader);
        pageShader.setVec3("viewPosition", camera.position);
        pageShader.setVec3("ambientLight", ambientLight);

        models[1].drawModel(pageShader); // Disegna il modello della pagina
    }
    else
    {
		currentTimePage = 0.0f; // Resetta il tempo corrente della pagina se l'animazione non è iniziata
    }

	previousTimePage = glfwGetTime(); // Aggiorna il tempo precedente della pagina

	// Disegna lo skybox
	modelMatrix = Matrix4x4f();
	modelMatrix = modelMatrix.model(Vector3f(0.0f), Vector3f(1.0f), 90.0f, x_axis); // Ruota lo skybox se necessario
	skybox.draw(skyboxShader, viewMatrix, projMatrix, modelMatrix);
}

void Scene::update(float currentTime)
{
    if (isAnimationStarted)
    {
        if (isPreviousObjectVisible)
        {
			scaleModel -= 0.001f; // Decrementa la scala del modello precedente
            
            if (scaleModel <= 0)
            {
				scaleModel = 0.0f; // Assicurati che la scala non scenda sotto 0
                isPreviousObjectVisible = false;
                currentVisibileObjectIndex = indexSelected;
			    isPageAnimationStarted = true; // Inizia l'animazione della pagina
            }
        }

        //ROTAZIONE
        if (currentTime - lastTime >= 1.0 / 60.0) // aggiorna ogni 1/60 di secondo
        {
            rotation += 1.0f; // incrementa l'angolo di rotazione
            lastTime = currentTime; // aggiorna il tempo dell'ultimo frame

            if (isPageAnimationStarted)
            {
                rotationPage += 1.0f; // incrementa l'angolo di rotazione della pagina

                if (rotationPage >= 180.0f) // resetta la rotazione dopo un giro completo
	            {
	            	rotationPage = 0.0f;
		        	isPageAnimationEnded = true; // L'animazione della pagina è completata
		        	isPageAnimationStarted = false; // Ferma l'animazione della pagina
	            }
            }
        }

	    

		if (isPageAnimationEnded && !isCurrentObjectVisible)
		{
			scaleModel += 0.001f; // Incrementa la scala del modello attuale

            if (scaleModel >= 1)
            {
				scaleModel = 1.0f; // Assicurati che la scala non superi 1
				isCurrentObjectVisible = true; // L'oggetto attualmente visibile è visibile
				isAnimationCompleted = true; // L'animazione totale è completata
				isAnimationStarted = false; // Ferma l'animazione
				isPageAnimationEnded = false; // Resetta l'animazione della pagina
            }
		}

    }
    else
    {
        if (currentTime - lastTime >= 1.0 / 60.0) // aggiorna ogni 1/60 di secondo
        {
            rotation += 1.0f; // incrementa l'angolo di rotazione
            lastTime = currentTime; // aggiorna il tempo dell'ultimo frame
        }
    }
    
}

void Scene::showObject(int index)
{
    //scala e traslazione
	if (index >= 0 && index < models.size())
	{
		indexSelected = index; // Aggiorna l'indice dell'oggetto visibile
	}
	else
	{
		std::cout << "Indice oggetto non valido: " << index << std::endl;
	}
}

void Scene::changeObject(int index)
{
    
}

void Scene::updateCommonMatrices(Shader& shader, const Matrix4x4f& model, const Matrix4x4f& view, const Matrix4x4f& proj)
{
    shader.setMat4("model", model);
    shader.setMat4("view", view);
    shader.setMat4("proj", proj);
}

void Scene::updateViewMatrix(Vector3f position, Vector3f target, Vector3f up)
{
	viewMatrix = viewMatrix.view(position, target, up); // Crea la matrice di vista
}
