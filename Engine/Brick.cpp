#include "Brick.h"
#include <assert.h>
#include <cmath>

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

bool Brick::CheckBallCollision(const Ball& ball) const
{
	return !destroyed && rect.IsOverlappingWith(ball.GetRect());
}

void Brick::ExecuteBallCollision(Ball& ball)
{
	assert(CheckBallCollision(ball));

	Vec2 ballPos = ball.GetCenter();

	if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - GetCenter()).x))
	{
		ball.ReboundY();
	}
	else if (ballPos.x <= rect.right &&		//Checks if ball is in between the sides of brick
			ballPos.x >= rect.left)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundX();
	}
	destroyed = true;
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}

