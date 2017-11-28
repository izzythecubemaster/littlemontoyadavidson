#include "Display.h"

/*
Samuel Davidson
ssims10@cnm.edu
Display.cpp - P3 perspective and view
*/

Display::Display(GLuint width, GLuint height, string title)
{
	const GLubyte *renderer;
	const GLubyte *version;

	/* start GL context and O/S window using the GLFW helper library */
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
	}

	// GLFW Hints
	//IJM: Enables 8x Anti-aliasing
	glfwWindowHint(GLFW_SAMPLES, 4);

	//window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	//IJM: Start in Fullscreen
	window = glfwCreateWindow(width, height, "Pacman Animation", glfwGetPrimaryMonitor(), NULL);
	
	//IJM: Locks mouse cursor in window
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (!window) {
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	//mouse and cursor callbacks
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, glfw_cursor_position_callback);

	/* start GLEW extension handler */
	glewExperimental = GL_TRUE;
	glewInit();

	/* get version info */
	renderer = glGetString(GL_RENDERER); /* get renderer string */
	version = glGetString(GL_VERSION);	 /* version as a string */
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	/* tell GL to only draw onto a pixel if the shape is closer to the viewer
	than anything already drawn at that pixel */
	glEnable(GL_DEPTH_TEST); /* enable depth-testing */
							 /* with LESS depth-testing interprets a smaller depth value as meaning "closer" */
	glDepthFunc(GL_LESS);


}

void Display::Update()
{
	/* update other events like input handling */
	glfwPollEvents();
	/* put the stuff we've been drawing onto the display */
	glfwSwapBuffers(window);

	if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_ESCAPE))
	{
		glfwSetWindowShouldClose(window, 1);
	}
}

void Display::Clear(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	/* wipe the drawing surface clear */
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

Display::~Display()
{
	/* close GL context and any other GLFW resources */
	glfwTerminate();
}
