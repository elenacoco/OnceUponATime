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

	static void debugError(const string& message)
	{
		GLenum error = glGetError();
		if (error != GL_NO_ERROR)
		{
			cout << message << ", OpenGL Error: " << error << endl;
		}
	}
};