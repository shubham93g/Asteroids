#pragma once
#include <SDL_scancode.h>
#include <SDL_rect.h>
#include <math.h>

class GameState
{
private:
	int yPosDelta, xPosDelta;
	double angle;
	SDL_Point *points;
	int numberOfPoints;
	int a, b, size;
	const int pixelsPerMove = 5;

	inline int rotateX(int x, int y, double cosTheta, double sinTheta) {
		return x*cosTheta - y*sinTheta;
	}

	inline int rotateY(int x, int y, double cosTheta, double sinTheta){
		return x*sinTheta + y*cosTheta;
	}
	void recalculatePoints(int x, int y, int size);
	void recalculatePoints(int x, int y, int size, double rotation);
public:
	GameState();
	
	~GameState();
	const SDL_Point* getPoints();
	const int getNumber();
	void handleInput(const Uint8 * keystates);
	void update();
};

