#ifndef MENU_H
#define MENU_H

#include "GameState.h"
#include "UserInput.h"

#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
using namespace glm;

class Menu : public GameState
{
private:
	bool loadBMP(char* path, GLuint &GUIelement);
	GLuint playGame[2]; //0 = Normal, 1 = selected
	GLuint exitGame[2];
	int selectedButton;

	vec2 playButtonCorners[4];
	vec2 exitButtonCorners[4];
public:
	Menu();
	~Menu();
	int update(UserInput* input);
	char getType();

	void getButtonData(char type, GLuint& tex, vec2 buttonCorners[]);
};

#endif