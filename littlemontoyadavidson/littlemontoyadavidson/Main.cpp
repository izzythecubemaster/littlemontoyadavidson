#include <GL/glew.h>		/* include GLEW and new version of GL on Windows */
#include <GL/glfw3.h>		/* GLFW helper library */
#include <stdio.h>
#include <cassert>
#include "MathFuncs.h"
#include "Shader.h"
#include "Transform.h"
#include "Display.h"
#include "obj_parser.h"
#include "ObjModel.h"
#include "Texture.h"
#include "Camera.h"
#include "Functions.h"
#include "Plane.h"

/*
Little Montoya Davidson
ssims10@cnm.edu
Main.cpp | P6 - Pacman
*/

GLFWwindow *window = NULL;
GLuint width = 1280, height = 720;
Camera camera;


int main(int argc, char** argv)
{
	ClassHeader();

	//create a display
	Display display(width, height, "Little Montoya Davidson | P6 - Pacman");
	
	//VP
	mat4 view = look_at(vec3(0.0f, 30.0f, 30.0f), vec3(0.0f, 0.0f, -1.0f), vec3(0.0f, 1.0f, 0.0f));
	mat4 proj = perspective(85.0f, (float)width / (float)height, 0.1f, 200.0f);

	//making pacman object
	Shader pacShader("shader");
	ObjModel pacMan(&pacShader, "planet.obj");
	pacShader.Use();
	glActiveTexture(GL_TEXTURE0);
	Texture pacTex("pacman.jpg");
	Transform pacTrans;
	pacTrans.SetScale(vec3(3.0f, 3.0f, 3.0f));
	pacTrans.SetPos(vec3(0.0f, 3.0f, 0.0f));
	mat4 pacModel = pacTrans.GetModel();
	mat4 pacMVP = proj * view * pacModel;
	GLuint pacMatrix = glGetUniformLocation(pacShader.GetProgramID(), "MVP");
	glUniformMatrix4fv(pacMatrix, 1, GL_FALSE, pacMVP.m);

	//make plane and axes
	Shader basicShader("basic");
	Plane plane(&basicShader);
	basicShader.Use();
	//axis trans
	Transform planeTrans;
	mat4 planeModel = planeTrans.GetModel();
	mat4 planeMVP = proj * view * planeModel;

	GLuint planeMatrix = glGetUniformLocation(basicShader.GetProgramID(), "MVP");
	glUniformMatrix4fv(planeMatrix, 1, GL_FALSE, planeMVP.m);


	while (!glfwWindowShouldClose(window)) {

		//clear display
		display.Clear(0.0f, 0.0f, 0.0f, 1.0f);
		glDepthMask(GL_TRUE);

		//pacman
		pacShader.Use();
		glBindVertexArray(pacMan.GetVAO()); //draw points from the currently bound VAO with current
		pacTex.Bind(0);
		glDrawArrays(GL_TRIANGLES, 0, pacMan.GetDrawCount());
		pacMVP = proj * camera.GetWorldToViewMatrix() * pacModel;
		glUniformMatrix4fv(pacMatrix, 1, GL_FALSE, pacMVP.m);

		//axis
		basicShader.Use();
		glBindVertexArray(plane.GetVAO());
		glDrawElements(GL_TRIANGLES, plane.GetDrawCount(), GL_UNSIGNED_SHORT, (void*)0);
		planeMVP = proj * camera.GetWorldToViewMatrix() * planeModel;
		glUniformMatrix4fv(planeMatrix, 1, GL_FALSE, planeMVP.m);

		
		display.Update();
	}


	/* close GL context and any other GLFW resources */
	glfwTerminate();
	return 0;
}