#include "RectangleArea.h"


RectangleArea::RectangleArea(Point pos, unsigned int w, unsigned int h) : position(pos), width(w), height(h)
{
}

RectangleArea::RectangleArea(unsigned int w, unsigned int h) : RectangleArea(Point(0, 0), w, h)
{
}

unsigned int RectangleArea::getWidth() const
{
	return width;
}

unsigned int RectangleArea::getHeight() const
{
	return height;
}

const Point &RectangleArea::getPosition() const
{
	return position;
}

void RectangleArea::setWidth(unsigned int w)
{
	width = w;
}

void RectangleArea::setHeight(unsigned int h)
{
	height = h;
}

void RectangleArea::setPosition(Point pos)
{
	position = pos;
}