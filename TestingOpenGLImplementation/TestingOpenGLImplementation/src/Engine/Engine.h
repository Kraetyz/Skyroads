#ifndef ENGINE_H
#define ENGINE_H
#include "../Basic/DebugLog.h"
#include "ShaderProgram.h"
#include "../Game/Menu.h"

#include <glm/glm.hpp>
using namespace glm;

class Engine
{
private:
	ShaderProgram* BMP;
	GLuint BMPbuf;

	void renderMenu(Menu* m);
	void renderBMP(GLuint tex, vec2* corners);
public:
	Engine();
	~Engine();
	void render(GameState* state);
};

#endif