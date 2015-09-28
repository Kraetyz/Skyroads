#ifndef ENGINE_H
#define ENGINE_H
#include "../Basic/DebugLog.h"
#include "../Game/GameState.h"

class Engine
{
private:

public:
	Engine();
	~Engine();
	void render(GameState* state);
};

#endif