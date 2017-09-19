#pragma once
#include "Geometry.h"
class Entity {
protected:
	Geometry geometry;
	void setGeometry(Geometry geometry);
public:
	Geometry getGeometry();
	virtual void update() = 0;
};