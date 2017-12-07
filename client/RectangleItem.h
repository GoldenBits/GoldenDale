#pragma once

#include "StdInc.h"

#include "../lib/RectangleArea.h"
#include "render/RenderItem.h"
#include <string>

class Texture;

class RectangleItem : public RectangleArea, public RenderItem
{
public:
	RectangleItem(int w, int h);
	~RectangleItem();
	Texture * texture;
};

