#pragma once

#include "Area.h"

class RectangleArea : public Area
{
public:
	RectangleArea(Point pos, unsigned int w, unsigned int h);
	RectangleArea(unsigned int w, unsigned int h);

	unsigned int getWidth() const override;
	unsigned int getHeight() const override;

	const Point &getPosition() const override;

	void setWidth(unsigned int w) override;
	void setHeight(unsigned int h) override;

	void setPosition(Point pos) override;
private:
	Point position;
	unsigned int width = 0, height = 0;
};