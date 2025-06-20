#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "importGL.h"

using namespace std;

class Utils
{
public:
	static string readFile(const string& filePath);

	static void debugError(const string& message) //prende un messaggio di errore e lo stampa se c'è un errore OpenGL
	{
		GLenum error = glGetError(); //prende l'errore OpenGL
		if (error != GL_NO_ERROR)
		{
			cout << message << ", OpenGL Error: " << error << endl;
		}
	}
};