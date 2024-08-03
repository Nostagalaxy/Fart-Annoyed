#include "Ball.h"

Ball::Ball(const Vec2& pos_in, const Vec2& vel_in)
{
	pos = pos_in;
	vel = vel_in;
}

void Ball::Draw(Graphics& gfx) const
{
	//Create center vector
	const Vec2 center = Vec2(pos.x + radius, pos.y + radius);

	//Takes center position of ball and graphics obj
	SpriteCodex::DrawBall(center, gfx);
}
