#include "Brick.h"

Brick::Brick(const Rectf& rect_in, const Color& color_in)
{
	rect = rect_in;
	color = color_in;
}

void Brick::Draw(Graphics& gfx) const
{
	gfx.DrawRect(rect.left, rect.top, rect.right, rect.bottom, color);
}
