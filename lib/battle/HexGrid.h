#pragma once
#include "field/HexField.h"
#include <memory>
#include <vector>

class HexGrid
{
public:
	void setGrid(int width, int height);
private:
	std::vector<std::shared_ptr<HexField>> grid;
};

