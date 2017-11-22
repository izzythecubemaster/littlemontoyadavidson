#ifndef CAMERA_H
#define CAMERA_H
#include "MathFuncs.h"

class Camera
{
	vec3 position;  //camera
	vec4 viewDirection; // normalized, length 1
	vec3 UP;
	vec3 oldMousePosition;
	vec3 moveDirection;
	const float MOVEMENT_SPEED = 0.1f;

public:
	Camera();
	mat4 GetWorldToViewMatrix() const;
	void MouseUpdate(const vec3& newMousePosition);
	void MoveBackward();
	void MoveForward();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void ResetLookAt();
};


#endif // !CAMERA_H