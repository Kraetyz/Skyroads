#include "UserInput.h"

UserInput::UserInput(GLFWwindow* wndhandle)
{
	wnd = wndhandle;
}

void UserInput::update()
{
	keyState = glfwGetKey(wnd, GLFW_KEY_UP);
	if (keyState == GLFW_PRESS)
		UP = true;
	else
		UP = false;
	keyState = glfwGetKey(wnd, GLFW_KEY_DOWN);
	if (keyState == GLFW_PRESS)
		DOWN = true;
	else
		DOWN = false;
	keyState = glfwGetKey(wnd, GLFW_KEY_LEFT);
	if (keyState == GLFW_PRESS)
		LEFT = true;
	else
		LEFT = false;
	keyState = glfwGetKey(wnd, GLFW_KEY_RIGHT);
	if (keyState == GLFW_PRESS)
		RIGHT = true;
	else
		RIGHT = false;
	keyState = glfwGetKey(wnd, GLFW_KEY_SPACE);
	if (keyState == GLFW_PRESS)
		SPACE = true;
	else
		SPACE = false;
	keyState = glfwGetKey(wnd, GLFW_KEY_ESCAPE);
	if (keyState == GLFW_PRESS)
		ESC = true;
	else
		ESC = false;
}

bool UserInput::getKey(string keyName)
{
	if (keyName == "UP")
		return UP;
	if (keyName == "DOWN")
		return DOWN;
	if (keyName == "LEFT")
		return LEFT;
	if (keyName == "RIGHT")
		return RIGHT;
	if (keyName == "SPACE")
		return SPACE;
	if (keyName == "ESC")
		return ESC;
	return false;
}