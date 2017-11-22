/*
Samuel Davidson
ssims10@cnm.edu
Functions.h - P5 Galaxy
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <GL/glew.h>
#include <GL/glfw3.h>
#include <iostream>
#include "MathFuncs.h"
#include "Camera.h"
#include <vector>
using namespace std;

//bool values for each vao
extern Camera camera;
extern GLFWwindow* window;

//header
void ClassHeader();

void glfw_cursor_position_callback(GLFWwindow *window, double xPos, double yPos);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void updateDelta();
vec3 updateOrbit(GLfloat distance);
vec3 updateOrbitY(GLfloat distance);
vector<vec3> CalculateOffsets(int instances);
vec3 updateMoonOrbit(GLfloat distSun, GLfloat distPlanet);
#endif // !FUNCTIONS_H
