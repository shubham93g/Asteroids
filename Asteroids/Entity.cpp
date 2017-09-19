#include "Entity.h"

void Entity::setGeometry(Geometry geometry)
{
	this->geometry = geometry;
}

Geometry Entity::getGeometry()
{
	return geometry;
}
