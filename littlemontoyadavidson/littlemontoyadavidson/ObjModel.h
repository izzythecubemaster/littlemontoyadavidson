#pragma once
#include <string>
#include "obj_parser.h" 
#include "Shader.h"
using namespace std;

class ObjModel
{
private:
	GLfloat *vp = NULL; // array of vertex points
	GLfloat *vn = NULL; // array of vertex normals
	GLfloat *vt = NULL; // array of texture coordinates
	GLint g_point_count = 0;  
	GLuint vertexArrayObject;
	Shader *shader;
	GLuint drawCount;
	enum
	{
		POSITION_VB,	//0
		TEXCOORD_VB,	//1				
		NUM_BUFFERS	    //2 = number of buffers
	};
	GLuint vertexBufferObject[NUM_BUFFERS];
	virtual void ProcessData();
public:
	ObjModel();
	ObjModel(Shader *shade, const char* filename);
	~ObjModel();
	GLuint GetVAO() { return vertexArrayObject; }
	GLuint GetDrawCount() { return drawCount; }
	
};

