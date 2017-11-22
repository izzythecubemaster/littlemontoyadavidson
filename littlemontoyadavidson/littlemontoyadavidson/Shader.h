#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <GL\glew.h>
#include <GL\glfw3.h>

using namespace std;


class Shader
{
private:
	GLuint programID;
	GLuint shaders[2];
	GLuint NUM_SHADERS = 2;

	string LoadShader(const string& fileName);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	GLuint CreateShader(const string& text, GLenum shaderType);

public:

	GLuint GetProgramID() { return programID; }
	Shader(const string& filename);
	void Use();
	Shader();
	~Shader();
};

