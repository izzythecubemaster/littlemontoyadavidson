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
GLuint width = 3840, height = 2160;
Camera camera;


int main(int argc, char** argv)
{
	ClassHeader();

	//create a display
	Display display(width, height, "Little Montoya Davidson | P6 - Pacman");
	
	//VP
	mat4 view = look_at(vec3(5.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f), vec3(0.0f, 1.0f , 0.0f));
	mat4 proj = perspective(85.0f, (float)width / (float)height, 0.1f, 200.0f);

	//making pacman object
	Shader pacTopShader("shader");
	ObjModel pacTop(&pacTopShader, "pactop.obj");
	pacTopShader.Use();
	glActiveTexture(GL_TEXTURE0);
	Texture pacTopTex("pactop.png");
	Transform pacTopTrans;
	pacTopTrans.SetScale(vec3(3.0f, 3.0f, 3.0f));
	pacTopTrans.SetPos(vec3(0.0f, 3.0f, 0.0f));
	//pacTopTrans.SetAngleX(-25.0f);
	mat4 pacTopModel = pacTopTrans.GetModel();
	mat4 pacTopMVP = proj * view * pacTopModel;
	GLuint pacTopMatrix = glGetUniformLocation(pacTopShader.GetProgramID(), "MVP");
	glUniformMatrix4fv(pacTopMatrix, 1, GL_FALSE, pacTopMVP.m);

	Shader pacBotShader("shader");
	ObjModel pacBot(&pacTopShader, "pachalf.obj");
	pacBotShader.Use();
	glActiveTexture(GL_TEXTURE0);
	Texture pacBotTex("pacbot.png");
	Transform pacBotTrans;
	pacBotTrans.SetScale(vec3(3.0f, 3.0f, 3.0f));
	//pacBotTrans.SetAngleX(25.0f);
	pacBotTrans.SetPos(vec3(0.0f, 3.0f, 0.0f));
	mat4 pacBotModel = pacBotTrans.GetModel();
	mat4 pacBotMVP = proj * view * pacBotModel;
	GLuint pacBotMatrix = glGetUniformLocation(pacTopShader.GetProgramID(), "MVP");
	glUniformMatrix4fv(pacBotMatrix, 1, GL_FALSE, pacBotMVP.m);

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
		static double previous_seconds = glfwGetTime();
		double current_seconds = glfwGetTime();
		double elapsed_seconds = current_seconds - previous_seconds;
		int speedTest = elapsed_seconds * 100;
		double speed = elapsed_seconds * 100.0f;

		//clear display
		display.Clear(0.0f, 0.0f, 0.0f, 1.0f);
		glDepthMask(GL_TRUE);

		//pacman
		pacTopShader.Use();

		// Pacman's top half animation
		if (speedTest < 45) { pacTopTrans.SetAngleX(-speed); }
		else if (speedTest >= 45 && speedTest < 90) { pacTopTrans.SetAngleX(speed - 90); }
		else if (speedTest >= 90 && speedTest < 135) { pacTopTrans.SetAngleX(-speed + 90); }
		else if (speedTest >= 135 && speedTest < 180) { pacTopTrans.SetAngleX(speed + 180); }
		else if (speedTest >= 180 && speedTest < 225) { pacTopTrans.SetAngleX(-speed + 180); }
		else if (speedTest >= 225 && speedTest < 270) { pacTopTrans.SetAngleX(speed + 90); }
		else if (speedTest >= 270 && speedTest < 315) { pacTopTrans.SetAngleX(-speed - 90); }
		else if (speedTest >= 315 && speedTest < 360) { pacTopTrans.SetAngleX(speed); }
		else { pacTopTrans.SetAngleX(0); }

		if (speedTest < 360) { pacTopTrans.SetPos(vec3(0.0f, 3.0f, speed / 15)); }
		else { pacTopTrans.SetPos(pacTopTrans.GetPos()); }

		glBindVertexArray(pacTop.GetVAO()); //draw points from the currently bound VAO with current
		pacTopTex.Bind(0);
		glDrawArrays(GL_TRIANGLES, 0, pacTop.GetDrawCount());
		pacTopModel = pacTopTrans.GetModel();
		pacTopMVP = proj * camera.GetWorldToViewMatrix() * pacTopModel;
		glUniformMatrix4fv(pacTopMatrix, 1, GL_FALSE, pacTopMVP.m);

		pacBotShader.Use();

		//Pacman's bottom half animation
		if (speedTest < 45) { pacBotTrans.SetAngleX(speed); }
		else if (speedTest >= 45 && speedTest < 90) { pacBotTrans.SetAngleX(-speed + 90); }
		else if (speedTest >= 90 && speedTest < 135) { pacBotTrans.SetAngleX(speed - 90); }
		else if (speedTest >= 135 && speedTest < 180) { pacBotTrans.SetAngleX(-speed + 180); }
		else if (speedTest >= 180 && speedTest < 225) { pacBotTrans.SetAngleX(speed + 180); }
		else if (speedTest >= 225 && speedTest < 270) { pacBotTrans.SetAngleX(-speed - 90); }
		else if (speedTest >= 270 && speedTest < 315) { pacBotTrans.SetAngleX(speed + 90); }
		else if (speedTest >= 315 && speedTest < 360) { pacBotTrans.SetAngleX(-speed); }
		else { pacBotTrans.SetAngleX(0); }

		if (speedTest < 360) { pacBotTrans.SetPos(vec3(0.0f, 3.0f, speed / 15)); }
		else { pacBotTrans.SetPos(pacBotTrans.GetPos()); }

		glBindVertexArray(pacBot.GetVAO()); //draw points from the currently bound VAO with current
		pacBotTex.Bind(0);
		pacBotModel = pacBotTrans.GetModel();
		pacBotMVP = proj * camera.GetWorldToViewMatrix() * pacBotModel;
		glDrawArrays(GL_TRIANGLES, 0, pacBot.GetDrawCount());
		glUniformMatrix4fv(pacBotMatrix, 1, GL_FALSE, pacBotMVP.m);


		//axis
		/*basicShader.Use();
		glBindVertexArray(plane.GetVAO());
		glDrawElements(GL_TRIANGLES, plane.GetDrawCount(), GL_UNSIGNED_SHORT, (void*)0);
		planeMVP = proj * camera.GetWorldToViewMatrix() * planeModel;
		glUniformMatrix4fv(planeMatrix, 1, GL_FALSE, planeMVP.m);
*/
		
		display.Update();
	}


	/* close GL context and any other GLFW resources */
	glfwTerminate();
	return 0;
}