#pragma once
#include <string>

using namespace std;

class Window {

public:

	string title;
	int width;
	int height;



	Window(int width, int height, string title);
};