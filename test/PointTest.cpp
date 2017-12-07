#include "StdInc.h"
#include "lib/Point.h"

TEST(PointTest, setupPosition)
{
    Point p(50,100);

    EXPECT_EQ(p.getX(), 50);
    EXPECT_EQ(p.getY(), 100);
}

TEST(PointTest, copyPosition)
{
    Point p(50,100);
    Point p2(p);

    EXPECT_EQ(p2.getX(), 50);
    EXPECT_EQ(p2.getY(), 100);
}