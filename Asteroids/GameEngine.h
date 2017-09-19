#pragma once
#include <SDL.h>
#include "GameState.h"
#include <vector>
class GameEngine
{
private:
	SDL_Window * window;
	SDL_Renderer * renderer;
public:
	GameEngine();
	~GameEngine();
	void init();
	bool handleInputAndUpdate(GameState &gameState);
	void draw(GameState &gameStatee);
};

