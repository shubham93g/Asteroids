#pragma once
#include "Entity.h"
#include <math.h>
class Bullet :public Entity
{
protected:
	int a, b, height, rotationPivotX, rotationPivotY;
	double x1, x2, y1, y2, unitX, unitY,angle;
	void doRotateFromInitial();
	inline int rotateX(int x, int y, double cosTheta, double sinTheta) {
		return x*cosTheta - y*sinTheta;
	}

	inline int rotateY(int x, int y, double cosTheta, double sinTheta) {
		return x*sinTheta + y*cosTheta;
	}
public:
	Bullet(int x, int y, int height, double angle, int pivotX, int pivotY);
	~Bullet();
	// Inherited via Entity
	virtual void update() override;
};

