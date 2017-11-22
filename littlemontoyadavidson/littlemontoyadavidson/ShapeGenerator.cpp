#include "ShapeGenerator.h"
#include "Vertex.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <algorithm>
//#include "gl_utils.h"
#include "MathFuncs.h"
#include <assert.h>


using namespace std;

#define NUM_ARRAY_ELEMENTS(a) sizeof(a) / sizeof(*a)

vec3 RandomColor()
{
	vec3 ret;
	ret.v[0] = rand() / (float)RAND_MAX;
	ret.v[1] = rand() / (float)RAND_MAX;
	ret.v[2] = rand() / (float)RAND_MAX;
	return ret;
}

ShapeData ShapeGenerator::makeTriangle()
{
	ShapeData ret;
	Vertex myTri[] =
	{
		vec3(0.0f, 1.0f, 0.0f),
		vec3(1.0f, 0.0f, 0.0f),

		vec3(-1.0f, -1.0f, 0.0f),
		vec3(0.0f, 1.0f, 0.0f),

		vec3(1.0f, -1.0f, 0.0f),
		vec3(0.0f, 0.0f, 1.0f)
	};

	GLushort indices[] = { 0, 1, 2, 0, 3, 4 };

	ret.numVertices = NUM_ARRAY_ELEMENTS(myTri);
	ret.vertices = new Vertex[ret.numVertices];
	memcpy(ret.vertices, myTri, sizeof(myTri));

	ret.numIndices = NUM_ARRAY_ELEMENTS(indices);
	ret.indices = new GLushort[ret.numIndices];
	memcpy(ret.indices, indices, sizeof(indices));
	return ret;
}

ShapeData ShapeGenerator::makeCube()
{

	ShapeData ret;

	Vertex myCube[] =
	{
		vec3(-1.0f, 1.0f, 1.0f),	//0
		vec3(1.0f, 0.0f, 1.0f),		//Color
		vec3(1.0f, 1.0f, 1.0f),	    //1
		vec3(0.0f, 1.0f, 0.0f),		//Color
		vec3(1.0f, 1.0f, -1.0f),	//2
		vec3(0.0f, 0.0f, 1.0f),		//Color
		vec3(-1.0f, 1.0f, -1.0f),	//3
		vec3(1.0f, 1.0f, 1.0f),		//Color

		vec3(-1.0f, 1.0f, -1.0f),	//4
		vec3(1.0f, 0.0f, 1.0f),		//Color
		vec3(1.0f, 1.0f, -1.0f),	//5
		vec3(0.0f, 0.5f, 0.2f),		//Color
		vec3(1.0f, -1.0f, -1.0f),	//6
		vec3(0.8f, 0.6f, 0.4f),		//Color
		vec3(-1.0f, -1.0f, -1.0f),	//7
		vec3(0.3f, 1.0f, 0.5f),		//Color

		vec3(1.0f, 1.0f, -1.0f),	//8
		vec3(0.2f, 0.5f, 0.2f),		//Color
		vec3(1.0f, 1.0f, 1.0f),		//9
		vec3(0.9f, 0.3f, 0.7f),		//Color
		vec3(1.0f, -1.0f, 1.0f),	//10
		vec3(0.3f, 0.7f, 0.5f),		//Color
		vec3(1.0f, -1.0f, -1.0f),	//11
		vec3(0.5f, 0.7f, 0.5f),		//Color

		vec3(-1.0f, 1.0f, 1.0f),	//12
		vec3(0.7f, 0.8f, 0.2f),		//Color
		vec3(-1.0f, 1.0f, -1.0f),	//13
		vec3(0.5f, 0.7f, 0.3f),		//Color
		vec3(-1.0f, -1.0f, -1.0f),	//14
		vec3(0.4f, 0.7f, 0.7f),		//Color
		vec3(-1.0f, -1.0f, 1.0f),	//15
		vec3(0.2f, 0.5f, 1.0f),		//Color

		vec3(1.0f, 1.0f, 1.0f),		//16
		vec3(0.6f, 1.0f, 0.7f),		//Color
		vec3(-1.0f, 1.0f, 1.0f),	//17
		vec3(0.6f, 0.4f, 0.8f),		//Color
		vec3(-1.0f, -1.0f, 1.0f),	//18
		vec3(0.2f, 0.8f, 0.7f),		//Color
		vec3(1.0f, -1.0f, 1.0f),	//19
		vec3(0.2f, 0.7f, 1.0f),		//Color

		vec3(1.0f, -1.0f, -1.0f),	//20
		vec3(0.8f, 0.3f, 0.7f),		//Color
		vec3(-1.0f, -1.0f, -1.0f),	//21
		vec3(0.8f, 0.9f, 0.5f),		//Color
		vec3(-1.0f, -1.0f, 1.0f),	//22
		vec3(0.5f, 0.8f, 0.5f),		//Color
		vec3(1.0f, -1.0f, 1.0f),	//23
		vec3(0.9f, 1.0f, 0.2f),		//Color
	};
	GLushort cubeIndices[] = { 
		0,  1,  2,  0,  2 , 3,		//top
		4,  5,  6,  4,  6,  7,		//front
		8,  9, 10,  8, 10, 11,		//right
		12, 13, 14, 12, 14, 15,		//left
		16, 17, 18, 16, 18, 19,		//back
		20, 22, 21, 20, 23, 22		//bottom
	};

	ret.numVertices = NUM_ARRAY_ELEMENTS(myCube);
	ret.vertices = new Vertex[ret.numVertices];
	memcpy(ret.vertices, myCube, sizeof(myCube));

	ret.numIndices = NUM_ARRAY_ELEMENTS(cubeIndices);
	//ret.numIndices = sizeof(cubeIndices) / sizeof(*cubeIndices);
	ret.indices = new GLushort[ret.numIndices];
	memcpy(ret.indices, cubeIndices, sizeof(cubeIndices));
	return ret;
}

ShapeData ShapeGenerator::MakePyramid()
{
	ShapeData ret;
	//Vertex pyramid[] = {

	//	//Front Face
	//	vec3(-1.0f, -1.0f,  1.0f), vec3(1.0f, 0.0f, 0.0f),	// 0 front left bottom, red
	//	vec3(1.0f, -1.0f,  1.0f), vec3(0.0f, 1.0f, 0.0f),	 // 1 front right bottom, green
	//	vec3(0.0f, 1.0f,  0.0f), vec3(0.8f, 0.8f, 0.8f),	// 4 apex, light gray
	//														//Right Face
	//	vec3(1.0f, -1.0f,  1.0f),vec3(0.0f, 1.0f, 0.0f),	// 1 front right bottom, green
	//	vec3(1.0f, -1.0f, -1.0f), vec3(0.0f, 0.0f, 1.0f),	// 2 back right bottom, blue
	//	vec3(0.0f,  1.0f,  0.0f), vec3(0.8f, 0.8f, 0.8),	// 4 apex, light gray
	//														// Back Face
	//	vec3(1.0f, -1.0f, -1.0f), vec3(0.0f, 0.0f, 1.0f),	// 2 back right bottom, blue
	//	vec3(-1.0f, -1.0f, -1.0f), vec3(0.8f, 0.8f, 0.8f),	// 3 back left bottom, light gray
	//	vec3(0.0f,  1.0f,  0.0f), vec3(0.8f, 0.8f, 0.8f),	// 4 apex, light gray
	//														// Left Face
	//	vec3(-1.0f, -1.0f, -1.0f), vec3(0.8f, 0.8f, 0.8),	// 3 back left bottom, light gray
	//	vec3(-1.0f, -1.0f,  1.0f), vec3(1.0f, 0.0f, 0.0f),	// 0 front left bottom, red
	//	vec3(0.0f,  1.0f,  0.0f), vec3(0.8f, 0.8f, 0.8f),	// 4 apex, light gray
	//														// Bottom Face front
	//	vec3(-1.0f, -1.0f,  1.0f), vec3(1.0f, 0.0f, 0.0f),	// 0 front left bottom, red
	//	vec3(1.0f, -1.0f,  1.0f), vec3(0.0f, 1.0f, 0.0f),	 // 1 front right bottom, green
	//	vec3(1.0f, -1.0f, -1.0f), vec3(0.0f, 0.0f, 1.0f),	// 2 back right bottom, blue

	//														// Bottom Face back
	//	vec3(-1.0f, -1.0f,  1.0f), vec3(1.0f, 0.0f, 0.0f),	// 0 front left bottom, red
	//	vec3(1.0f, -1.0f, -1.0f), vec3(0.0f, 0.0f, 1.0f),	// 2 back right bottom, blue
	//	vec3(-1.0f, -1.0f, -1.0f), vec3(0.8f, 0.8f, 0.8f)	// 3 back left bottom, light gray

	//};

	//For indexed drawing, need 4 vertices:
	Vertex pyramid[] = {
		vec3(-1.0f, -1.0f, 1.0f), vec3(1.0f, 0.0f, 0.0f),	// 0 front left bottom, red
		vec3(1.0f, -1.0f, 1.0f), vec3(0.0f, 1.0f, 0.0f),	 // 1 front right bottom, green
		vec3(1.0f, -1.0f, -1.0f), vec3(0.0f, 0.0f, 1.0f),	// 2 back right bottom, blue
		vec3(-1.0f, -1.0f, -1.0f), vec3(0.8f, 0.8f, 0.8f),	// 3 back left bottom, light gray
		vec3(0.0f,  1.0f,  0.0f), vec3(0.8f, 0.8f, 0.8f),	// 4 apex, light gray
	};

	GLshort indices[] = {
		0, 1, 4,
		1, 2, 4,
		2, 3, 4,
		3, 0, 4,
		0, 1, 2,
		0, 2, 3
	};


	ret.numVertices = NUM_ARRAY_ELEMENTS(pyramid);
	ret.vertices = new Vertex[ret.numVertices];
	memcpy(ret.vertices, pyramid, sizeof(pyramid));

	ret.numIndices = NUM_ARRAY_ELEMENTS(indices);
	//ret.numIndices = sizeof(indices) / sizeof(*indices);
	ret.indices = new GLushort[ret.numIndices];
	memcpy(ret.indices, indices, sizeof(indices));
	return ret;
}

ShapeData ShapeGenerator::MakeTriangleFan()
{
	#define PI 3.14159265359
	ShapeData ret;

	float triHeight = 1.0f;
	float negHeight = -triHeight;
	float triWidth = triHeight + 0.5f;
	
	Vertex fan[14];
	fan[0].position = vec3(0.0, triHeight, 0.0);
	GLfloat angle = 0.0f;

	for (unsigned int x = 1; x < 14; x++)
	{
		angle += float(PI / 6.0f);
		GLfloat xtri = triWidth*sin(angle);
		GLfloat ytri = -triHeight;
		GLfloat ztri = triWidth*cos(angle);
		fan[x].position = vec3(xtri, ytri, ztri);
	}

	for (unsigned int i = 0; i < 14; i++)
	{
		fan[i].color = RandomColor();
	}
	
		//fan[0].color = vec3(1.0, 0.0, 0.0);
		//fan[1].color = vec3(1.0, 0.0, 0.0);
		//fan[2].color = vec3(0.0, 1.0, 0.0);
		//fan[3].color = vec3(0.0, 1.0, 0.0);
		//fan[4].color = vec3(0.0, 0.0, 1.0);
		//fan[5].color = vec3(0.0, 0.0, 1.0);
		//fan[6].color = vec3(0.0, 0.0, 1.0);
		//fan[7].color = vec3(0.0, 1.0, 0.0);
		//fan[8].color = vec3(1.0, 0.0, 0.0);
		//fan[9].color = vec3(0.0, 1.0, 0.0);
		//fan[10].color = vec3(0.0, 0.0, 1.0);
		//fan[12].color = vec3(0.0, 1.0, 0.0);
		//fan[13].color = vec3(0.0, 0.0, 1.0);
		//fan[14].color = vec3(0.0, 1.0, 0.0);

		GLushort indices[] = { 
			0, 1, 2,
			2, 3, 0,
			0, 3, 4,
			0, 4, 5,
			0, 5, 6,
			0, 6, 7,
			0, 7, 8,
			0, 8, 9,
			0, 9, 10,
			0, 10, 11,
			0, 11, 1

		};
	
	ret.numVertices = NUM_ARRAY_ELEMENTS(fan);
	ret.vertices = new Vertex[ret.numVertices];
	memcpy(ret.vertices, fan, sizeof(fan));

	ret.numIndices = NUM_ARRAY_ELEMENTS(indices);
	//ret.numIndices = sizeof(indices) / sizeof(*indices);
	ret.indices = new GLushort[ret.numIndices];
	memcpy(ret.indices, indices, sizeof(indices));
	return ret;

}

ShapeData ShapeGenerator::MakeAxes()
{
	ShapeData ret;

	Vertex ax[] =
		{   vec3(-5.0f, 0.0f,0.0f), vec3(1.0, 0.0, 0.0),
			vec3(5.0f, 0.0f, 0.0f), vec3(1.0, 0.0, 0.0),
			vec3(0.0f, -5.0f, 0.0f), vec3(0.0, 1.0, 0.0),
			vec3(0.0f, 5.0f, 0.0f),  vec3(0.0, 1.0, 0.0),
			vec3(0.0f, 0.0f, -5.0f), vec3(0.0, 0.0, 1.0),
			vec3(0.0f, 0.0f, 5.0f), vec3(0.0, 0.0, 1.0) };	

	ret.numVertices = NUM_ARRAY_ELEMENTS(ax);
	ret.vertices = new Vertex[ret.numVertices];
	memcpy(ret.vertices, ax, sizeof(ax));

	return ret;
}

ShapeData ShapeGenerator::MakePlane()
{
	ShapeData ret;
	Vertex plane[] = {
		
		// X     Y    Z     R     G     B
		vec3(-30.0f, 0.0f, -30.0f), vec3(1.0f, 0.0f, 1.0f),    //top right
		vec3(30.0f, 0.0f, -30.0f), vec3(1.0f, 0.0f, 1.0f),	//top left
		vec3(30.0f, 0.0f, 30.0f), vec3(1.0f, 0.0f, 1.0f),	//bottom right

	//	vec3(1.0f, -1.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f),	//bottom right, duplicate
	//	vec3(-1.0f, 1.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f),		//top left, duplicate
		vec3(-30.0f, 0.0f, 30.0f), vec3(1.0f, 0.0f, 1.0f)    //bottom left

	};

	GLushort indices[] = {
		0, 1, 2,
		0, 3, 2
	};

	ret.numVertices = NUM_ARRAY_ELEMENTS(plane);
	ret.vertices = new Vertex[ret.numVertices];
	memcpy(ret.vertices, plane, sizeof(plane));

	ret.numIndices = NUM_ARRAY_ELEMENTS(indices);
	//ret.numIndices = sizeof(indices) / sizeof(*indices);
	ret.indices = new GLushort[ret.numIndices];
	memcpy(ret.indices, indices, sizeof(indices));
	return ret;
}

ShapeData ShapeGenerator::makeArrow()
{
	ShapeData ret;
	Vertex arrow[] =
	{
		//topside of arrow head
			vec3(0.00f, 0.25f, -0.25f),	//0
			vec3(1.00f, 0.00f, 0.00f),	//color
			vec3(0.50f, 0.25f, -0.25f),	//1
			vec3(1.00f, 0.00f, 0.00f),	//color
			vec3(0.00f, 0.25f, -1.00f),	//2
			vec3(1.00f, 0.00f, 0.00f),	//color
			vec3(-0.50f, 0.25f, -0.25f), //3
			vec3(1.00f, 0.00f, 0.00f),	//color

			//bottom side of arrow head
			vec3(0.00f, -0.25f, -0.25f),	//4
			vec3(0.00f, 0.00f, 1.00f),	//color
			vec3(0.50f, -0.25f, -0.25f), //5
			vec3(0.00f, 0.00f, 1.00f),	//color
			vec3(0.00f, -0.25f, -1.00f),//6
			vec3(0.00f, 0.00f, 1.00f),	//color
			vec3(-0.50f, -0.25f, -0.25f),	//7
			vec3(0.00f, 0.00f, 1.00f),	//color

			//right side of arrow tip
			vec3(0.50f, 0.25f, -0.25f),	//8
			vec3(0.60f, 1.00f, 0.00f),	//color
			vec3(0.00f, 0.25f, -1.00f),	//9
			vec3(0.60f, 1.00f, 0.00f),	//color
			vec3(0.00f, -0.25f, -1.00f),	//10
			vec3(0.60f, 1.00f, 0.00f),	//color
			vec3(0.50f, -0.25f, -0.25f),	//11
			vec3(0.60f, 1.00f, 0.00f),	//color

			//left side of arrow tip
			vec3(0.00f, 0.25f, -1.00f),	//12
			vec3(0.00f, 1.00f, 0.00f),	//color
			vec3(-0.50f, 0.25f, -0.25f), //13
			vec3(0.00f, 1.00f, 0.00f),	//color
			vec3(0.00f, -0.25f, -1.00f),	//14
			vec3(0.00f, 1.00f, 0.00f),	//color
			vec3(-0.50f, -0.25f, -0.25f),	//15
			vec3(0.00f, 1.00f, 0.00f),	//color

			//back side of arrow tip
			vec3(-0.50f, 0.25f, -0.25f),	//16
			vec3(0.50f, 0.50f, 0.50f),	//color
			vec3(0.50f, 0.25f, -0.25f), //17
			vec3(0.50f, 0.50f, 0.50f),	//color
			vec3(-0.50f, -0.25f, -0.25f),	//18
			vec3(0.50f, 0.50f, 0.50f),	//color
			vec3(0.50f, -0.25f, -0.25f),	//19
			vec3(0.50f, 0.50f, 0.50f),	//color

			//top side of back of arrow
			vec3(0.25f, 0.25f, -0.25f),	//20
			vec3(1.00f, 0.00f, 0.00f),	//color
			vec3(0.25f, 0.25f, 1.00f), //21
			vec3(1.00f, 0.00f, 0.00f),	//color
			vec3(-0.25f, 0.25f, 1.00f),	//22
			vec3(1.00f, 0.00f, 0.00f),	//color
			vec3(-0.25f, 0.25f, -0.25f),	//23
			vec3(1.00f, 0.00f, 0.00f),	//color

			//bottom side of back of arrow
			vec3(0.25f, -0.25f, -0.25f),	//24
			vec3(0.00f, 0.00f, 1.00f),	//color
			vec3(0.25f, -0.25f, 1.00f),//25
			vec3(0.00f, 0.00f, 1.00f),	//color
			vec3(-0.25f, -0.25f, 1.00f),	//26
			vec3(0.00f, 0.00f, 1.00f),	//color
			vec3(-0.25f, -0.25f, -0.25f),	//27
			vec3(0.00f, 0.00f, 1.00f),	//color

			//right side of back of arrow
			vec3(0.25f, 0.25f, -0.25f),	//28
			vec3(0.60f, 1.00f, 0.00f),	//color
			vec3(0.25f, -0.25f, -0.25f),//29
			vec3(0.60f, 1.00f, 0.00f),	//color
			vec3(0.25f, -0.25f, 1.00f),	//30
			vec3(0.60f, 1.00f, 0.00f),	//color
			vec3(0.25f, 0.25f, 1.00f),	//31
			vec3(0.60f, 1.00f, 0.00f),	//color

			//left side of back of arrow
			vec3(-0.25f, 0.25f, -0.25f),	//32
			vec3(0.00f, 1.00f, 0.00f),	//color
			vec3(-0.25f, -0.25f, -0.25f), //33
			vec3(0.00f, 1.00f, 0.00f),	//color
			vec3(-0.25f, -0.25f, 1.00f),	//34
			vec3(0.00f, 1.00f, 0.00f),	//color
			vec3(-0.25f, 0.25f, 1.00f),	//35
			vec3(0.00f, 1.00f, 0.00f),	//color

			//back side of back of arrow
			vec3(-0.25f, 0.25f, 1.00f),	//3
			vec3(0.50f, 0.50f, 0.50f),	//color
			vec3(0.25f, 0.25f, 1.00f), //37
			vec3(0.50f, 0.50f, 0.50f),	//color
			vec3(-0.25f, -0.25f, 1.00f),	//38
			vec3(0.50f, 0.50f, 0.50f),	//color
			vec3(0.25f, -0.25f, 1.00f),	//39
			vec3(0.50f, 0.50f, 0.50f),	//color
	};

	GLushort indices[] =
	{
		0, 1, 2,	//top
		0, 2, 3,
		4, 6, 5,	//bottom
		4, 7, 6,
		8, 10, 9,	//right side of arrow tip
		8, 11, 10,
		12, 15, 13, //left side of arrow tip
		12, 14, 15,
		16, 19, 17,	//back side of arrow tip
		16, 18, 19,
		20, 22, 21,	//top side of back of arrow
		20, 23, 22,
		24, 25, 26, //bottom side of back of arrow
		24, 26, 27,
		28, 30, 29,	//right side of back of arrow
		28, 31, 30,
		32, 33, 34, //left side of back of arrow
		32, 34, 35,
		36, 39, 37, //back side of back of arrow
		36, 38, 39

	};

	ret.numVertices = NUM_ARRAY_ELEMENTS(arrow);
	ret.vertices = new Vertex[ret.numVertices];
	memcpy(ret.vertices, arrow, sizeof(arrow));

	ret.numIndices = NUM_ARRAY_ELEMENTS(indices);
	//ret.numIndices = sizeof(indices) / sizeof(*indices);
	ret.indices = new GLushort[ret.numIndices];
	memcpy(ret.indices, indices, sizeof(indices));
	return ret;
}

