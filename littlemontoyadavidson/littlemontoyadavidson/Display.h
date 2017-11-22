/*
Samuel Davidson
ssims10@cnm.edu
Display.h - P3 perspective and view
*/
#ifndef DISPLAY_H
#define DISPLAY_H

#include <GL\glew.h>
#include <GL\glfw3.h>
#include <string>
#include "Functions.h"

using namespace std;

extern GLFWwindow* window;

class Display
{
public:
	Display(GLuint width, GLuint height, string title);
	void Update();
	void Clear(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	~Display();
};

#endif // !DISPLAY_H



