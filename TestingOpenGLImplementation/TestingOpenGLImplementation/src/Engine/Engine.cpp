#include "Engine.h"

Engine::Engine()
{
	BMP = new ShaderProgram("src/Shaders/BMPrenderVertex.txt", "src/Shaders/BMPrenderFrag.txt");
	glGenBuffers(1, &BMPbuf);

	glClearColor(0, 0, 0, 1);
}

Engine::~Engine()
{
	delete BMP;
}

void Engine::render(GameState* state)
{
	glClear(GL_COLOR_BUFFER_BIT);
	if (state->getType() == 'M')
		renderMenu((Menu*)state);
}

void Engine::renderMenu(Menu* m)
{
	vec2 corners[4];
	GLuint tex;
	m->getButtonData('E', tex, corners);
	renderBMP(tex, corners);
	m->getButtonData('P', tex, corners);
	renderBMP(tex, corners);
}

void Engine::renderBMP(GLuint tex, vec2 corners[])
{
	glBindBuffer(GL_ARRAY_BUFFER, BMPbuf);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, corners, GL_STATIC_DRAW);

	//define vertex data layout
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0); //the vertex attribute object will remember its enabled attributes
	GLuint prog = BMP->getProgram();
	glUseProgram(prog);
	GLuint vertexPos = glGetAttribLocation(prog, "vertex_position");
	glVertexAttribPointer(vertexPos, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);

	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, tex);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glDeleteVertexArrays(1, &vao);
}