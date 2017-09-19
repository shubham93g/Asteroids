#include "Box.h"

void Box::doRotateFromInitial()
{
	double cosResult = cos(angle*3.14159265 / 180);
	double sinResult = sin(angle*3.14159265 / 180);

	int x1 = rotateX(a - rotationPivotX, b - rotationPivotY, cosResult, sinResult) + rotationPivotX;
	int y1 = rotateY(a - rotationPivotX, b - rotationPivotY, cosResult, sinResult) + rotationPivotY;

	int x2 = rotateX(a - rotationPivotX, b + size - rotationPivotY, cosResult, sinResult) + rotationPivotX;
	int y2 = rotateY(a - rotationPivotX, b + size - rotationPivotY, cosResult, sinResult) + rotationPivotY;

	int x3 = rotateX(a + size - rotationPivotX, b + size - rotationPivotY, cosResult, sinResult) + rotationPivotX;
	int y3 = rotateY(a + size - rotationPivotX, b + size - rotationPivotY, cosResult, sinResult) + rotationPivotY;

	int x4 = rotateX(a + size - rotationPivotX, b - rotationPivotY, cosResult, sinResult) + rotationPivotX;
	int y4 = rotateY(a + size - rotationPivotX, b - rotationPivotY, cosResult, sinResult) + rotationPivotY;

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
	rotationPivotX = getCentreX();
	rotationPivotY = getCentreY();
}

void Box::addRotation(double angle, int xPivot, int yPivot)
{
	this->angle += angle;
	rotationPivotX = xPivot;
	rotationPivotY = yPivot;
}

int Box::getCentreX()
{
	return a + size / 2;
}

int Box::getCentreY()
{
	return b + size / 2;
}

void Box::update()
{
	doRotateFromInitial();
}
