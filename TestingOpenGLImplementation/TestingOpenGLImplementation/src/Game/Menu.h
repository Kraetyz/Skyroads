#ifndef MENU_H
#define MENU_H

#include "GameState.h"
#include "UserInput.h"

#include <gl/glew.h>
#include <GLFW/glfw3.h>

class Menu : public GameState
{
private:
	bool loadBMP(char* path, GLuint GUIelement);
	GLuint playGame[2]; //0 = Normal, 1 = selected
	GLuint exitGame[2];
	int selectedButton;
public:
	Menu();
	~Menu();
	int update(UserInput* input);
	char getType();
};

#endif