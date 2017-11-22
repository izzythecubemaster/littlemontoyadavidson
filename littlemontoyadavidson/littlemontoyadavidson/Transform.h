#ifndef TRANSFORM_H
#define TRANSFORM_H

//Ivonne Nelson
//inelson1@cnm.edu

/* This class does the calculations for moving the object. It manages the model matrix. 
It can be rotated, in 3-D, it can be translated, and it can be scaled.
This is accomplished by use of matrix multiplication.*/

#include <GL/glew.h>
#include <GL/glfw3.h>
#include "MathFuncs.h"

class Transform
{
public:
	Transform(const vec3& posit = vec3(0.0f, 0.0f, 0.0f), const vec3& scales = vec3(1.0f, 1.0f, 1.0f))
	{
		position = posit;
		scaleIt = scales;
	}
	

	mat4 GetModel()const
	{
		mat4 posMatrix = translate(identity_mat4(), position);
		mat4 scaleMatrix = scale(identity_mat4(), scaleIt);
		
		//Do rotation by adding Angles
		mat4 rotXMatrix = rotate_x_deg(identity_mat4(), angleX);
		mat4 rotYMatrix = rotate_y_deg(identity_mat4(), angleY);
		mat4 rotZMatrix = rotate_z_deg(identity_mat4(), angleZ);
		mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

		//you can comment out any type of motion you are not using
		return identity_mat4()* posMatrix * rotMatrix * scaleMatrix;
	}

	vec3& GetPos() { return position; }
	vec3& GetScale() { return scaleIt; }
	//float& GetAngle() { return angle; }

	void SetPos(vec3 posit) { position = posit; }
	void SetScale(vec3 scales) { scaleIt = scales; }
	void SetAngleX(float ang) { angleX = ang; }
	void SetAngleY(float ang) { angleY = ang; }
	void SetAngleZ(float ang) { angleZ = ang; }

private:
	vec3 position;
	vec3 scaleIt;
	float angleX = 0.0f;
	float angleY = 0.0f;
	float angleZ = 0.0f;

};

#endif