#include "Menu.h"
#include <string>

#define NW 0
#define SW 1
#define NE 2
#define SE 3

Menu::Menu()
{
	loadBMP("BMPs/PlayGame.bmp", playGame[0]);
	loadBMP("BMPs/PlayGame-Selected.bmp", playGame[1]);
	loadBMP("BMPs/ExitGame.bmp", exitGame[0]);
	loadBMP("BMPs/ExitGame-Selected.bmp", exitGame[1]);

	selectedButton = 0;
	
	vec2 halfScreen = vec2(400, 300);

	playButtonCorners[NW] = vec2(272, 400);
	playButtonCorners[SW] = vec2(272, 528);
	playButtonCorners[NE] = vec2(528, 400);
	playButtonCorners[SE] = vec2(528, 528);

	exitButtonCorners[NW] = vec2(272, 200);
	exitButtonCorners[SW] = vec2(272, 328);
	exitButtonCorners[NE] = vec2(528, 200);
	exitButtonCorners[SE] = vec2(528, 328);

	for (int c = 0; c < 4; c++)
	{
		playButtonCorners[c] -= halfScreen;
		playButtonCorners[c] /= halfScreen;

		exitButtonCorners[c] -= halfScreen;
		exitButtonCorners[c] /= halfScreen;
	}
}

Menu::~Menu()
{
}

int Menu::update(UserInput* input)
{
	if (input->getKey("DOWN") && selectedButton != 1)
		selectedButton = 1;
	if (input->getKey("UP") && selectedButton != 0)
		selectedButton = 0;
	if (input->getKey("SPACE") && selectedButton == 1)
		return 999;
	return 0;
}

char Menu::getType()
{
	return 'M';
}

void Menu::getButtonData(char type, GLuint &tex, vec2 buttonCorners[])
{
	if (type == 'P')
	{
		tex = playGame[(selectedButton+1)%2]; //That's stupid Adam
		buttonCorners[NW] = playButtonCorners[NW];
		buttonCorners[NE] = playButtonCorners[NE];
		buttonCorners[SW] = playButtonCorners[SW];
		buttonCorners[SE] = playButtonCorners[SE];
	}
	else if (type == 'E')
	{
		tex = exitGame[selectedButton];
		buttonCorners[NW] = exitButtonCorners[NW];
		buttonCorners[NE] = exitButtonCorners[NE];
		buttonCorners[SW] = exitButtonCorners[SW];
		buttonCorners[SE] = exitButtonCorners[SE];
	}
}

bool Menu::loadBMP(char* imagepath, GLuint &GUIelement)
{
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;

	FILE* file;
	fopen_s(&file, imagepath, "rb");

	if (!file)
		return false;

	if (fread(header, 1, 54, file) != 54) // If not 54 bytes read : problem
		return false;

	if (header[0] != 'B' || header[1] != 'M')
		return false;

	// Read ints from the byte array
	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);

	// Some BMP files are misformatted, guess missing information
	if (imageSize == 0)
		imageSize = width*height * 3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos == 0)
		dataPos = 54; // The BMP header is done that way

	// Create a buffer
	data = new unsigned char[imageSize];

	// Read the actual data from the file into the buffer
	fread(data, 1, imageSize, file);

	//Everything is in memory now, the file can be closed
	fclose(file);

	// Create one OpenGL texture
	glGenTextures(1, &GUIelement);

	glActiveTexture(GL_TEXTURE0);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, GUIelement);

	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	delete[] data;

	return true;
}