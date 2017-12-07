#pragma once

#include <utility>

class Point
{
public:
	Point(int x, int y);
	Point(const Point &point) = default;

	int getX() const;
	int getY() const;

	bool operator==(const Point &point) const;
private:
	int x = 0, y = 0;
};