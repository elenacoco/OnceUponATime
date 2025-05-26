#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Utils
{
public:
	static string readFile(const string& filePath);
};