#ifndef USERINPUT_H
#define USERINPUT_H

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <string>

using namespace std;

class UserInput
{
private:
	GLFWwindow* wnd;
	bool RIGHT; bool LEFT; bool UP; bool DOWN;
	bool SPACE;
	bool ESC;

	int keyState; //Keep this as a member variable to ease up on the creation of new ints. Minimal but hey it's something lol
public:
	UserInput(GLFWwindow* wndhandle);
	void update();
	bool getKey(string keyName);
};

#endif