#include "Plane.h"

Plane::Plane(Shader *shade)
{
	plane = ShapeGenerator::MakePlane();
	shader = shade;
	StoreData();
}

void Plane::StoreData()
{
	vertexArrayObject = 0;
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	//Change for Indexing.  Add enum for vertex buffer array
	glGenBuffers(NUM_BUFFERS, vertexBufferObject);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, plane.vertexBufferSize(), plane.vertices, GL_STATIC_DRAW);
	glBindAttribLocation(shader->GetProgramID(), 0, "vertex_position");
	glEnableVertexAttribArray(0);	//position
	glBindAttribLocation(shader->GetProgramID(), 1, "inputColour");
	glEnableVertexAttribArray(1);	//color
									//when adding color, must fix stride, which is distance from the beginning of set 1 to the next set. 
									//last argument is how far to the first attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (char*)(3 * sizeof(float)));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexBufferObject[INDEX_VB]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, plane.indexBufferSize(), plane.indices, GL_STATIC_DRAW);

	drawCount = plane.numIndices;


	//Get Random translations for pyramids	
	numInstances = 1;
	vector<vec3> cubeOffsets = CalculateOffsets(numInstances);
	GLuint  instanceVBO_pyr;
	glGenBuffers(1, &instanceVBO_pyr);
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO_pyr);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeOffsets[0])* numInstances, &cubeOffsets[0], GL_STATIC_DRAW);

	//Then we also need to set its vertex attribute pointer and enable the vertex attribute :
	glEnableVertexAttribArray(2);
	glBindAttribLocation(shader->GetProgramID(), 2, "offset");
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glVertexAttribDivisor(2, 1);

	glBindVertexArray(0);
}


