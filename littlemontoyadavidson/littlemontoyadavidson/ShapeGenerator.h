#ifndef SHAPE_GENERATOR
#define SHAPE_GENERATOR

#include "ShapeData.h"
//#include "TeapotData.h"
class ShapeGenerator
{	
public: 
	static ShapeData makeTriangle();
	static ShapeData makeCube();
	static ShapeData makeArrow();
	static ShapeData MakePyramid();
	static ShapeData MakeTriangleFan();
	static ShapeData MakeAxes();
	static ShapeData MakePlane();
};


#endif
