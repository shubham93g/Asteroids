#pragma once
#include <SDL_scancode.h>
#include <SDL_rect.h>
#include <math.h>
#include "Box.h"
#include "Bullet.h"
#include <vector>

class GameState
{
private:
	int yPosDelta, xPosDelta;
	double angle;
	const int pixelsPerMove = 5;
	Bullet* bullet;
	Box* box;
	Box* head;

public:
	GameState();
	~GameState();
	std::vector<std::vector<SDL_Point>> getVectorPoints();
	void handleInput(const Uint8 * keystates);
	void update();
};

