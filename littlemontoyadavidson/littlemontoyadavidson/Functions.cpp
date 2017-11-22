#include "Functions.h"

/*
Samuel Davidson
ssims10@cnm.edu
Functions.cpp - P5 Galactic Stuff
*/


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_W && action == GLFW_REPEAT)
	{
		camera.MoveForward();
	}
	if (key == GLFW_KEY_S && action == GLFW_REPEAT)
	{
		camera.MoveBackward();
	}
	if ((key == GLFW_KEY_UP || key == GLFW_KEY_Q) && action == GLFW_REPEAT)
	{
		camera.MoveDown();
	}
	if ((key == GLFW_KEY_DOWN || key == GLFW_KEY_E) && action == GLFW_REPEAT)
	{
		camera.MoveUp();
	}
	if ((key == GLFW_KEY_RIGHT || key == GLFW_KEY_D) && action == GLFW_REPEAT)
	{
		camera.MoveRight();
	}
	if ((key == GLFW_KEY_LEFT || key == GLFW_KEY_A) && action == GLFW_REPEAT)
	{
		camera.MoveLeft();
	}
	if (key == GLFW_KEY_P && action == GLFW_PRESS)
	{
		
	}
	if (key == GLFW_KEY_R && action == GLFW_PRESS)
	{
		camera.ResetLookAt();
	}
}

void glfw_cursor_position_callback(GLFWwindow *window, double xPos, double yPos)
{
	vec3 newPos = vec3(float(xPos), float(yPos), 0.0);
	camera.MouseUpdate(newPos);
}


void ClassHeader()
{
	cout << "Samuel Davidson\nssims10@cnm.edu\nP5 - Galactic stuff.\n\n" <<
		"Q - Move Up\nE - Move Down\nW - Move Forward\nS - Move Backward\nA - Move Left\nD - Move Right\nR - Return to Start\nP - Change Speed\n\n";
}

vector<vec3> CalculateOffsets(int instances)
{
	vector<vec3> ret(instances);
	int offsets[3];
	vec3 trans;
	for (int i = 0; i < instances; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			offsets[x] = rand() % 7;
			if (offsets[x] % 2 == 0)
			{
				offsets[x] *= -1;
			}
			trans.v[x] = float(offsets[x]);
		}

		ret.at(i) = trans;
	}
	return ret;
}

