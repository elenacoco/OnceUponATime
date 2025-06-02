#include "Shader.h"

Shader::Shader(const string& vertexPath, const string& fragmentPath)
{
	//vertex shader
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	string vpath = Utils::readFile(vertexPath);
	const char* vertexSource = vpath.c_str();
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	int success;
	char infolog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
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
	if (!success)
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
	glDeleteShader(shaderID);
}

void Shader::useProgram()
{
	glUseProgram(shaderID);
}

void Shader::setInt(const char* uniform, int value)
{
	glUniform1i(glGetUniformLocation(shaderID, uniform), value);
}
