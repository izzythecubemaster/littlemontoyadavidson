//Ivonne Nelson
//inelson1@cnm.edu

//Texture.h

#pragma once
#include <GL/glew.h>
#include <string>
#include <iostream>
#include "stb_image.h"
using namespace std;

class Texture
{
public:
	Texture(const string& filename);

	void Bind(unsigned int unit); //you can bind up to 32 textures

	GLuint GetTexture() { return textureID; }
	
	virtual ~Texture();
private:	
	GLuint textureID = 0;
};

