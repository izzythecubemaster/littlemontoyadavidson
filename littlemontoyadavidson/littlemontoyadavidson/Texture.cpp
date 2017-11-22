//Ivonne Nelson
//inelson1@cnm.edu

//Texture.cpp


#include "Texture.h"
#include <assert.h>

//OpenGl reads all texture from 0 to 1 in both directions Up and Right are 1, Down and Left are 0

Texture::Texture(const string& filename)
{
	int x, y, numComponents;
	unsigned char* imageData = stbi_load(filename.c_str(), &x, &y, &numComponents, 4 );


	//Check  imageData
	if (imageData == NULL)
	{
		cerr << "\n Texture Loading failed for texture " << filename << endl;
	}
		
	glGenTextures(1, &textureID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

	//can set some parameters  - here is a selection
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//If texture resolution takes up more or less pixels than its resolution
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	GLfloat max_aniso = 0.0f;
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &max_aniso);
	// set the maximum!
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, max_aniso);




	stbi_image_free(imageData);
}

void Texture::Bind(unsigned int unit) //you can bind up to 32 textures
{
	//If you are using multiple textures and want to bind to a specific unit, use:
	//glActiveTexture(GL_TEXTURE0 + unit);
	//Also assert that texture is between 0 and 31, since that is the opengl range
	assert(unit >= 0 && unit <= 31);


	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);
}


Texture::~Texture()
{
	glDeleteTextures(1, &textureID);
}
