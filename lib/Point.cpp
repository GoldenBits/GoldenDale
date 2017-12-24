#include "Point.h"

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

bool Point::operator==(const Point &point) const
{
	return getX() == point.getX() && getY() == point.getY();
}


