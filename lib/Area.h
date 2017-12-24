#pragma once

#include "Point.h"

class Area
{
public:
	virtual unsigned int getWidth() const = 0;
	virtual unsigned int getHeight() const = 0;

	virtual const Point &getPosition() const = 0;

	virtual void setWidth(unsigned int w) = 0;
	virtual void setHeight(unsigned int h) = 0;

	virtual void setPosition(Point pos) = 0;
};