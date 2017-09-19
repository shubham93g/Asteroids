#include "GameState.h"

GameState::GameState()
{
	box = new Box(300, 200, 80);
	yPosDelta = 0;
}


GameState::~GameState()
{
	delete box;
}

std::vector<SDL_Point> GameState::getVectorPoints()
{
	return box->getGeometry().getPointVector();
}

void GameState::handleInput(const Uint8 * keystates)
{
	if (keystates[SDL_SCANCODE_UP]) {
		yPosDelta-=pixelsPerMove;
	}

	if (keystates[SDL_SCANCODE_DOWN]) {
		yPosDelta+=pixelsPerMove;
	}

	if (keystates[SDL_SCANCODE_LEFT]) {
		xPosDelta -= pixelsPerMove;
	}

	if (keystates[SDL_SCANCODE_RIGHT]) {
		xPosDelta += pixelsPerMove;
	}

	if (keystates[SDL_SCANCODE_D]) {
		box->addRotation(5.0);
	}

	if (keystates[SDL_SCANCODE_A]) {
		box->addRotation(-5.0);
	}
}

void GameState::update()
{
	box->update();
}
