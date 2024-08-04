#include "Brick.h"

Brick::Brick(const Rectf& rect_in, const Color& color_in)
{
	rect = rect_in;
	color = color_in;
}

void Brick::Draw(Graphics& gfx) const
{
	if (!destroyed)
	{
		gfx.DrawRect(int(rect.left), int(rect.top), int(rect.right), int(rect.bottom), color);
	}
}

bool Brick::DoBallCollision(Ball& ball)
{
	if (!destroyed)
	{
		if (rect.IsOverlappingWith(ball.GetRect()))
		{
			ball.ReboundY();
			destroyed = true;
			return true;
		}
	}
	return false;
}
