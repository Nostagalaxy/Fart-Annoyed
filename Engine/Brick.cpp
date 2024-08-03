#include "Brick.h"

Brick::Brick(const Rectf& rect_in, const Color& color_in)
{
	rect = rect_in;
	color = color_in;
}

void Brick::Draw(Graphics& gfx) const
{
	gfx.DrawRect(int(rect.left), int(rect.top), int(rect.right), int(rect.bottom), color);
}
