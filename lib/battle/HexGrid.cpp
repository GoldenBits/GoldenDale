#include "HexGrid.h"

void HexGrid::setGrid(int width, int height)
{
	for(int i = 0; i < height; i++)
		for(int j = 0; j < width; j++)
		{
			grid.push_back(std::make_shared<HexField>(j,i));
		}
}
