#include "GameState.h"

GameState::GameState()
{
	box = new Box(300, 200, 80);
	head = new Box(338, 200, 5);
	yPosDelta = 0;
}


GameState::~GameState()
{
	delete box;
}

std::vector<std::vector<SDL_Point>> GameState::getVectorPoints()
{
	std::vector<std::vector<SDL_Point>> vectorPoints;
	vectorPoints.push_back(box->getGeometry().getPointVector());
	vectorPoints.push_back(head->getGeometry().getPointVector());
	return vectorPoints;
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
		head->addRotation(5.0, box->getCentreX(), box->getCentreY());
	}

	if (keystates[SDL_SCANCODE_A]) {
		box->addRotation(-5.0);
		head->addRotation(-5.0, box->getCentreX(), box->getCentreY());
	}
}

void GameState::update()
{
	box->update();
	head->update();
}
