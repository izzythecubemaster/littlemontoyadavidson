#include "ObjModel.h"



ObjModel::ObjModel(Shader *shade, const char* filename)
{
	//Load obj mesh
	if (!load_obj_file(filename, vp, vt, vn, g_point_count)) {
		cerr << "ERROR: loading mesh file\n";

	}
	shader = shade;
	ProcessData();
}

void ObjModel::ProcessData()
{	
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	//Generate vbo's
	glGenBuffers(NUM_BUFFERS, vertexBufferObject);

	//Vbo for Position
	glGenBuffers(1, &vertexBufferObject[POSITION_VB]);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, 3 * g_point_count * sizeof(GLfloat), vp, GL_STATIC_DRAW);

	// Specify the layout of the vertex data
	//GLint posAttrib = glGetAttribLocation(ourShader.GetProgramID(), "vertex_position");
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);

	//Now create a vbo for the texCoords	
	glGenBuffers(1, &vertexBufferObject[TEXCOORD_VB]);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject[TEXCOORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, 2 * g_point_count * sizeof(GLfloat), vt, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	drawCount = g_point_count;
}


ObjModel::~ObjModel()
{
	glDeleteVertexArrays(1, &vertexArrayObject);
}
