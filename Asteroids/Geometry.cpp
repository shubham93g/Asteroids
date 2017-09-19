#include "Geometry.h"

void Geometry::addPoint(SDL_Point point)
{
	points.push_back(point);
}

void Geometry::updateGeometry(SDL_Point point, int position)
{
	if (position < points.capacity()) {
		points[position] = point;
	}
}

std::vector<SDL_Point> Geometry::getPointVector()
{
	return points;
}
