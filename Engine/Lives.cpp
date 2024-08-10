#include "Lives.h"

Lives::Lives(const Rectf& rect_in)
{
	rect = rect_in;
	lifeLost = false;
}

void Lives::removeLife()
{
	lifeLost = true;
}

void Lives::Draw(Graphics& gfx) const
{
	if (!lifeLost)
	{
		gfx.DrawRect(int(rect.left), int(rect.top), int(rect.right), int(rect.bottom), Colors::Yellow);
	}
}
