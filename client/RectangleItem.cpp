#include "RectangleItem.h"
#include "render/Texture.h"

RectangleItem::RectangleItem(int w, int h) : RectangleArea(w, h)
{
	setData();
	texture = new Texture();
}

RectangleItem::~RectangleItem()
{
	delete texture;
}
