#include "StdInc.h"
#include "lib/RectangleArea.h"

TEST(RectangleAreaTest, initialize)
{
    RectangleArea area(Point(-15, 20), 11, 12);
	EXPECT_EQ(area.getPosition(), Point(-15, 20));
	EXPECT_EQ(area.getWidth(), 11);
    EXPECT_EQ(area.getHeight(), 12);
}

TEST(RectangleAreaTest, setPosition)
{
    RectangleArea area(0,0);
    area.setPosition(Point(10,1));
    EXPECT_EQ(area.getPosition().getX(), 10);
	EXPECT_EQ(area.getPosition().getY(), 1);
	area.setPosition(Point(-13,-13));
	EXPECT_EQ(area.getPosition().getX(), -13);
	EXPECT_EQ(area.getPosition().getY(), -13);
}


TEST(RectangleAreaTest, setDimensions)
{
    RectangleArea area(0,0);
    area.setWidth(132);
    EXPECT_EQ(area.getWidth(), 132);
    area.setHeight(123081);
    EXPECT_EQ(area.getHeight(), 123081);
}

