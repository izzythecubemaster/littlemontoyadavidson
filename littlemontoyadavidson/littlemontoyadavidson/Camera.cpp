#include "Camera.h"

Camera::Camera():  //initalize camera
	position(0.0f, 30.0f, 30.0f),
	viewDirection(0.0f, 0.0f, -1.0f, 0.0),  //camera is looking down the -z axis - unit vector
	UP(0.0f, 1.0f, 0.0f)	//y-dir pos is up
{}

void Camera::ResetLookAt()
{
	position = vec3(0.0f, 30.0f, 30.0f);
	viewDirection = vec4(0.0f, 0.0f, -1.0f, 0.0);  //camera is looking down the -z axis - unit vector
	UP = vec3(0.0f, 1.0f, 0.0f);	//y-dir pos is up
}

mat4 Camera::GetWorldToViewMatrix() const
{		
	return look_at(position, vec3(viewDirection) + position, UP);
}

void Camera::MouseUpdate(const vec3& newMousePosition)
{
	//need to track old mouse position
	vec3 mouseDelta = newMousePosition - oldMousePosition; 
	if (length(mouseDelta) > 50)
	{
		oldMousePosition = newMousePosition;
		return;
	}

	const float ROTATIONAL_SPEED = 0.1f;
	moveDirection = cross(viewDirection, UP);

	versor vers = quat_from_axis_deg(-mouseDelta.v[1] * ROTATIONAL_SPEED, moveDirection.v[0], moveDirection.v[1], moveDirection.v[2]);
	mat4 rotater = quat_to_mat4(vers);

	//Rotate ViewDirection around the y axis an amount that the mouse has traveled
	mat4 totalRotator = rotater *  rotate_y_deg(identity_mat4(), -mouseDelta.v[0] * ROTATIONAL_SPEED);

	viewDirection = totalRotator * vec4(viewDirection, 1.0);
	//viewDirection = rotater * vec4(viewDirection, 1.0);
	//viewDirection = rotate_y_deg(identity_mat4(), -mouseDelta.v[0] * 0.5) * vec4(viewDirection, 1.0);
	
	
	//when you get the  vertical rotation fixed, create a final rotator matrix by multiplying
	//horizontal * vertical, then use that.
	oldMousePosition = newMousePosition;

}

void Camera::MoveBackward()
{
	position -= vec3(viewDirection) * MOVEMENT_SPEED;
}
void Camera::MoveForward()
{
	position += vec3(viewDirection) * MOVEMENT_SPEED;
}
void Camera::MoveLeft(){
	
	position -= moveDirection * MOVEMENT_SPEED;
}
void Camera::MoveRight(){
	
	position += moveDirection * MOVEMENT_SPEED;
}
void Camera::MoveUp()
{
	position += UP * -MOVEMENT_SPEED;
}
void Camera::MoveDown()
{
	position -= UP * -MOVEMENT_SPEED;
}