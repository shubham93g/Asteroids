#pragma once
#include "Entity.h"
class Box : public Entity {
protected:
	double angle;
	int size, a, b, rotationPivotX, rotationPivotY;
	inline int rotateX(int x, int y, double cosTheta, double sinTheta) {
		return x*cosTheta - y*sinTheta;
	}

	inline int rotateY(int x, int y, double cosTheta, double sinTheta) {
		return x*sinTheta + y*cosTheta;
	}
	void doRotateFromInitial();
public:
	Box(int x, int y, int size);
	void addRotation(double angle);
	void addRotation(double angle, int xPivot, int yPivot);
	int getCentreX();
	int getCentreY();
	// Inherited via Entity
	virtual void update() override;
};