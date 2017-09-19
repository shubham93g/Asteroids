#include "Box.h"

void Box::doRotateFromInitial()
{
	double cosResult = cos(angle*3.14159265 / 180);
	double sinResult = sin(angle*3.14159265 / 180);

	int xCentre = a + size / 2;
	int yCentre = b + size / 2;

	int x1 = rotateX(a - xCentre, b - yCentre, cosResult, sinResult) + xCentre;
	int y1 = rotateY(a - xCentre, b - yCentre, cosResult, sinResult) + yCentre;

	int x2 = rotateX(a - xCentre, b + size - yCentre, cosResult, sinResult) + xCentre;
	int y2 = rotateY(a - xCentre, b + size - yCentre, cosResult, sinResult) + yCentre;

	int x3 = rotateX(a + size - xCentre, b + size - yCentre, cosResult, sinResult) + xCentre;
	int y3 = rotateY(a + size - xCentre, b + size - yCentre, cosResult, sinResult) + yCentre;

	int x4 = rotateX(a + size - xCentre, b - yCentre, cosResult, sinResult) + xCentre;
	int y4 = rotateY(a + size - xCentre, b - yCentre, cosResult, sinResult) + yCentre;

	geometry.updateGeometry({ x1, y1 }, 0);
	geometry.updateGeometry({ x2, y2 }, 1);
	geometry.updateGeometry({ x3, y3 }, 2);
	geometry.updateGeometry({ x4, y4 }, 3);
	geometry.updateGeometry({ x1, y1 }, 4);
}

Box::Box(int x, int y, int size)
{
	a = x;
	b = y;
	angle = 0;
	Geometry geometry;
	geometry.addPoint({ x,y });
	geometry.addPoint({ x,y + size });
	geometry.addPoint({ x + size,y + size });
	geometry.addPoint({ x + size,y });
	geometry.addPoint({ x,y });
	setGeometry(geometry);
	this->size = size;
}

void Box::addRotation(double angle)
{
	this->angle += angle;
}

void Box::update()
{
	doRotateFromInitial();
}
