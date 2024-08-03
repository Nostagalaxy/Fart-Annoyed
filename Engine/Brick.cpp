#include "Brick.h"

Brick::Brick(const Rectf& rect_in, const Color& color_in)
{
	rect = rect_in;
	color = color_in;
}

void Brick::Draw(Graphics& gfx) const
{
	for (int x = int(rect.left); x <= int(rect.right); x++)
	{
		for (int y = int(rect.top); y <= int(rect.bottom); y++)
		{
			gfx.PutPixel(x, y, color);
		}
	}
}
