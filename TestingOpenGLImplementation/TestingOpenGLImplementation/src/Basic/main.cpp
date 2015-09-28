#include <ctime>

#include <glm/glm.hpp>

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32.lib")

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "DebugLog.h"
#include "../Game/Game.h"

//#include <vld.h>

int main(int argv, char* argc[])
{

	// flags are append existing file, print to console, print to file
#ifdef _DEBUG
	Debug::OpenDebugStream(false, true, true);
#endif
	srand((unsigned int)time(0));

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	GLFWwindow* wnd = 0;
	if (!glfwInit())
		exit(EXIT_FAILURE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, false);

	wnd = glfwCreateWindow(800, 600, "Skyroads", NULL, NULL);

	glfwMakeContextCurrent(wnd);
	glewInit();

	glfwSwapInterval(1);

	//Code for game
	Game* gameHandle = new Game(wnd);
	gameHandle->mainLoop();
	delete gameHandle;


	glfwDestroyWindow(wnd);
	glfwTerminate();

#ifdef _DEBUG
	Debug::CloseDebugStream();
#endif
	return 0;
}