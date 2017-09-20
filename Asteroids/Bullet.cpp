#include "Bullet.h"



Bullet::Bullet(int x, int y, int height, double angle, int pivotX, int pivotY)
{
	a = x;
	b = y;
	this->height = height;
	this->angle = angle;
	rotationPivotX = pivotX;
	rotationPivotY = pivotY;
	Geometry geometry;
	geometry.addPoint({ a,b });
	geometry.addPoint({ a,b - height });
	setGeometry(geometry);
	doRotateFromInitial();
}


Bullet::~Bullet()
{
}

void Bullet::update()
{
	double modifier = 0.03; //perupdate
	x1 = x1 + unitX*modifier;
	y1 = y1 + unitY*modifier;
	x2 = x2 + unitX*modifier;
	y2 = y2 + unitY*modifier;
	geometry.updateGeometry({ (int) x1, (int) y1 }, 0);
	geometry.updateGeometry({ (int) x2, (int) y2 }, 1);
}

void Bullet:: doRotateFromInitial()
{
	double cosResult = cos(angle*3.14159265 / 180);
	double sinResult = sin(angle*3.14159265 / 180);

	x1 = rotateX(a - rotationPivotX, b - rotationPivotY, cosResult, sinResult) + rotationPivotX;
	y1 = rotateY(a - rotationPivotX, b - rotationPivotY, cosResult, sinResult) + rotationPivotY;

	x2 = rotateX(a - rotationPivotX, b - height - rotationPivotY, cosResult, sinResult) + rotationPivotX;
	y2 = rotateY(a - rotationPivotX, b - height - rotationPivotY, cosResult, sinResult) + rotationPivotY;

	unitX = x2 - x1;
	unitY = y2 - y1;
	double magnitude = sqrt(pow(unitX, 2) + pow(unitY, 2));
	unitX = unitX / magnitude;
	unitY = unitY / magnitude;

	geometry.updateGeometry({ (int) x1, (int) y1 }, 0);
	geometry.updateGeometry({ (int) x2, (int) y2 }, 1);
}
