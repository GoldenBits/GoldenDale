#include "StdInc.h"
#include "mock/battle/Area.h"
using ::testing::Return;

TEST(GridTest, setupPosition)
{
	HexGrid grid(area);

	AreaMock area;
	EXPECT_CALL(area, getWidth()).Times(1).WillOnce(Return(100));

	EXPECT_EQ(area.getWidth(), 100);

}