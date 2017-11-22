//Ivonne Nelson
//inelson1@cnm.edu

//Shader.cpp

#include "Shader.h"


string Shader::LoadShader(const std::string& fileName)
{
	std::ifstream file;
	file.open((fileName).c_str());

	std::string output;
	std::string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
	{
		std::cerr << "Unable to load shader: " << fileName << std::endl;
	}

	return output;
}
void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		std::cerr << errorMessage << ": '" << error << "'" << std::endl;
	}
}

GLuint Shader::CreateShader(const string& text, GLenum shaderType)	//text is full test of the shader program
{
	GLuint shader = glCreateShader(shaderType);
	if (shader == 0)
		cerr << "\n Shader creation failed";

	//Have to convert std::string to c-string
	const GLchar* shaderSourceStrings[1];
	shaderSourceStrings[0] = text.c_str();
	GLint shaderSourceStringsLengths[1];
	shaderSourceStringsLengths[0] = text.length();

	glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringsLengths);
	glCompileShader(shader);

	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error compiling shader!");

	return shader;
}

Shader::Shader(const string& filename)
{
	programID = glCreateProgram();
	shaders[0] = CreateShader(LoadShader(filename + ".vert"), GL_VERTEX_SHADER);
	shaders[1] = CreateShader(LoadShader(filename + ".frag"), GL_FRAGMENT_SHADER);

	for (unsigned int i = 0; i < NUM_SHADERS; i++)
	{
		glAttachShader(programID, shaders[i]);
	}

	//Bind Attribute location tells opengl what part of the data to read in for which variable. 
	//glBindAttribLocation(programID, 0, "position");
	//glBindAttribLocation(programID, 1, "color");

	glLinkProgram(programID);
	CheckShaderError(programID, GL_LINK_STATUS, true, "Error linking shader program");

	glValidateProgram(programID);
	CheckShaderError(programID, GL_LINK_STATUS, true, "Invalid shader program");

	//gives access to the transform uniform.
	//uniformID = glGetUniformLocation(programID, "matrix");
}

void Shader::Use()
{
	glUseProgram(programID);
}




Shader::~Shader()
{
	for (unsigned int i = 0; i < NUM_SHADERS; i++)
	{
		glDetachShader(programID, shaders[i]);
		glDeleteShader(shaders[i]);
	}
	glDeleteProgram(programID);
}


Shader::Shader()
{
}