#include "Game.h"
#include <ctime>

Game::Game(GLFWwindow* wndhandle)
{
	wnd = wndhandle;
	input = new UserInput(wndhandle);

	cState = new Menu();

	engine = new Engine();
}

Game::~Game()
{
	delete input;
	delete cState;
	delete engine;
}

void Game::mainLoop()
{
	clock_t start = clock();
	float deltaTime = 0.0f;
	float clock;
	float lastClock = 0.0f;

	while (!glfwWindowShouldClose(wnd))
	{
		glfwPollEvents();
		clock = float((std::clock() - start) / (double)CLOCKS_PER_SEC);
		deltaTime = clock - lastClock;
		lastClock = clock;

		input->update();
		if (input->getKey("ESC"))
			glfwSetWindowShouldClose(wnd, 1);

		int stateMsg = cState->update(input);
		if (stateMsg == 999)
			glfwSetWindowShouldClose(wnd, 1);

		engine->render(cState);

		/*
		if (input->getKey("UP"))
			printf("Pressed\n");
		if (input->getKey("LEFT"))
			printf("Pressed\n");
		if (input->getKey("DOWN"))
			printf("Pressed\n");
		if (input->getKey("RIGHT"))
			printf("Pressed\n");
		if (input->getKey("SPACE"))
			printf("Pressed\n");
		*/

		glfwSwapBuffers(wnd);
	}
}