#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "UserInput.h"

class GameState
{
private:
	char stateType;
public:
	GameState();
	virtual ~GameState();
	virtual int update(UserInput* input) = 0;
	virtual char getType() = 0;
};

#endif