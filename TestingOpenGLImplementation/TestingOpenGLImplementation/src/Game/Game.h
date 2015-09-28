#ifndef GAME_H
#define GAME_H
#include "../Basic/DebugLog.h"
#include "UserInput.h"

#include "GameState.h"
#include "Menu.h"
#include "../Engine/Engine.h"

#include <GLFW/glfw3.h>

class Game
{
private:
	GLFWwindow* wnd;
	UserInput* input;
	GameState* cState;

	Engine* engine;
public:
	Game(GLFWwindow* wndhandle);
	~Game();
	void mainLoop();
};

#endif