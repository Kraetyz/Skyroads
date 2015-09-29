#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H
#include <string>
#include <fstream>
#include <vector>
#include <gl/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

class ShaderProgram
{
private:
	GLuint program;
	string getShader(const char* filePath);

	void compileErrorPrint(GLuint* shader);
	void linkErrorPrint(GLuint* program);
public:
	ShaderProgram(string vertShaderPath, string fragShaderPath);
	GLuint getProgram(){return program;}
};

#endif