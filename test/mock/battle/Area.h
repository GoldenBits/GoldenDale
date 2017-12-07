#include "StdInc.h"
#include "lib/Area.h"
#include "lib/Point.h"

class AreaMock : public Area
{
public:
	MOCK_CONST_METHOD0(getWidth, unsigned int());
	MOCK_CONST_METHOD0(getHeight, unsigned int());
	MOCK_CONST_METHOD0(getPosition, const Point&());
	MOCK_METHOD1(setWidth, void(unsigned int w));
	MOCK_METHOD1(setHeight, void(unsigned int h));
	MOCK_METHOD1(setPosition, void(Point pos));
};



