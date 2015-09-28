#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
private:
public:
	GameState();
	virtual ~GameState();
	virtual int update() = 0;
};

#endif