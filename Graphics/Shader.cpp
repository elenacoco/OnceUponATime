#include "Shader.h"

Shader::Shader(const string& vertexPath, const string& fragmentPath)
{
	//vertex shader
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER); //creiamo lo shader
	string vpath = Utils::readFile(vertexPath); //otteniamo il path
	const char* vertexSource = vpath.c_str();
	glShaderSource(vertexShader, 1, &vertexSource, NULL); //NULL per length
	glCompileShader(vertexShader);

	int success;
	char infolog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) //se lo shader non è compilato
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infolog);
		cout << "ERRORE::VERTEX SHADER NON COMPILATO\n" << infolog << endl;
	}

	//fragment shader
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	string fpath = Utils::readFile(fragmentPath);
	const char* fragmentSource = fpath.c_str();
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infolog);
		cout << "ERRORE::FRAGMENT SHADER NON COMPILATO\n" << infolog << endl;
	}

	//program
	shaderID = glCreateProgram();
	glAttachShader(shaderID, vertexShader);
	glAttachShader(shaderID, fragmentShader);
	glLinkProgram(shaderID);

	glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
	if (!success) //se il link non va a buon fine
	{
		glGetProgramInfoLog(shaderID, 512, NULL, infolog);
		cout << "ERRORE::PROGRAM::LINK FALLITO\n" << infolog << endl;
	}

	//cancello gli shader
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
}

void Shader::useProgram()
{
	glUseProgram(shaderID);
}

void Shader::setInt(const char* uniform, int value) //serve per le texture e setta la uniform della texture
{
	glUniform1i(glGetUniformLocation(shaderID, uniform), value);
}

void Shader::setMat4(const char* uniform, Matrix4x4f value)
{
	glUniformMatrix4fv(glGetUniformLocation(shaderID, uniform), 1, GL_TRUE, &value.a11); //GL_TRUE per trasporre la matrice e 
																						//&value.a11 è il riferimento al primo valore della matrice
}

void Shader::setVec3(const char* uniform, Vector3f value)
{
	glUniform3fv(glGetUniformLocation(shaderID, uniform), 1, &value.x);  // 1 è un vettore o un elemento di un vettore?
}
