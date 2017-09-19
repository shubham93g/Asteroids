#include "GameState.h"

GameState::GameState()
{
	yPosDelta = 0;
	numberOfPoints = 5;
	points = new SDL_Point[numberOfPoints];
	a = 300;
	b = 200;
	size = 40;
	angle = 0.0;
	recalculatePoints(a,b,size);
}

void GameState::recalculatePoints(int x, int y, int size)
{
	*points = { x, y };
	*(points + 1) = { x, y+size };
	*(points + 2) = { x+size, y+size };
	*(points + 3) = { x+size, y };
	*(points + 4) = { x, y };
}

void GameState::recalculatePoints(int x, int y, int size, double rotation)
{
	double cosResult = cos(rotation*3.14159265 / 180);
	double sinResult = sin(rotation*3.14159265 / 180);

	int xCentre = x + size / 2;
	int yCentre = y + size / 2;
	
	int x1 = rotateX(x - xCentre,y - yCentre, cosResult, sinResult) + xCentre;
	int y1 = rotateY(x - xCentre,y - yCentre, cosResult, sinResult) + yCentre;

	int x2 = rotateX(x - xCentre, y+size - yCentre, cosResult, sinResult) + xCentre;
	int y2 = rotateY(x - xCentre, y+size - yCentre, cosResult, sinResult) + yCentre;

	int x3 = rotateX(x+size - xCentre, y+size - yCentre, cosResult, sinResult) + xCentre;
	int y3 = rotateY(x+size - xCentre, y+size - yCentre, cosResult, sinResult) + yCentre;

	int x4 = rotateX(x+size - xCentre, y - yCentre, cosResult, sinResult) + xCentre;
	int y4 = rotateY(x+size - xCentre, y - yCentre, cosResult, sinResult) + yCentre;

	*points = { x1, y1 };
	*(points + 1) = { x2, y2 };
	*(points + 2) = { x3, y3 };
	*(points + 3) = { x4, y4 };
	*(points + 4) = { x1, y1 };
}


GameState::~GameState()
{
	delete points;
}

const SDL_Point* GameState::getPoints()
{
	return points;
}

const int GameState::getNumber()
{
	return numberOfPoints;
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
		angle += 5.00;
	}

	if (keystates[SDL_SCANCODE_A]) {
		angle -= 5.00;
	}
}

void GameState::update()
{
	recalculatePoints(a + xPosDelta, b+yPosDelta ,size, angle);
}
