//Ivonne Nelson

//inelson1@cnm.edu

//Pyramid.h

#ifndef CUBE_H
#define CUBE_H
#include <GL/glew.h>

#include "MathFuncs.h"
#include "Vertex.h"
#include "ShapeGenerator.h"
#include "ShapeData.h"
#include "Shader.h"
#include "Functions.h"
#include <vector>
//#include "Mesh.h"


extern GLuint width;
extern GLuint height;


class Plane
{
private:
	ShapeData plane;
	GLuint vertexArrayObject;
	Shader *shader;
	GLuint numInstances;
	GLuint drawCount;
	enum
	{
		POSITION_VB,	//0
						//COLOR_VB,		//1
						INDEX_VB,		//2
						NUM_BUFFERS	    //3 = number of buffers
	};
	GLuint vertexBufferObject[NUM_BUFFERS];
	void StoreData();
public:
	Plane(Shader *shade);
	~Plane() { glDeleteVertexArrays(1, &vertexArrayObject); }
	GLuint GetVAO() { return vertexArrayObject; }
	GLuint GetDrawCount() { return drawCount; }
	GLuint GetNumInstances() { return numInstances; }
};

#endif
