#pragma once
#include <SDL_scancode.h>
#include <SDL_rect.h>
#include <math.h>
#include "Box.h"
#include <vector>

class GameState
{
private:
	int yPosDelta, xPosDelta;
	const int pixelsPerMove = 5;
	Box* box;

public:
	GameState();
	~GameState();
	std::vector<SDL_Point> getVectorPoints();
	void handleInput(const Uint8 * keystates);
	void update();
};

