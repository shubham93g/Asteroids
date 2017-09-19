#pragma once
#include <SDL_rect.h>
#include <vector>

class Geometry {
private:
	std::vector<SDL_Point> points;
public:
	void addPoint(SDL_Point point);
	void updateGeometry(SDL_Point point, int position);
	std::vector<SDL_Point> getPointVector();
};