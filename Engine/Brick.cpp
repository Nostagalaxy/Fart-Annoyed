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
		gfx.DrawRect(int(rect.left), int(rect.top), int(rect.right), int(rect.bottom), Colors::Black);
		gfx.DrawRect(int(rect.left + padding), int(rect.top + padding), int(rect.right - padding), int(rect.bottom - padding), color);
	}
}

bool Brick::DoBallCollision(Ball& ball)
{
	if (!destroyed)
	{
		if (rect.IsOverlappingWith(ball.GetRect()))			//Checks for overlapping
		{
			if (ball.GetRect().right < rect.right &&		//Checks if ball is in between the sides of brick
				ball.GetRect().left > rect.left)
			{
				ball.ReboundY();
				destroyed = true;
				return true;
			}
			else
			{
				ball.ReboundX();
				destroyed = true;
				return true;
			}
		}
	}
	return false;
}

