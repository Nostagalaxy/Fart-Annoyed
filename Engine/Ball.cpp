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

void Ball::Update(const float dt)
{
	pos += vel * dt;
}

bool Ball::DoWallCollision(const Rectf& walls)
{
	bool collided = false;
	//const float diameter = 2.0f * radius;
	Rectf bRect = GetRect();//(pos, diameter, diameter);
	if (bRect.left < walls.left)
	{
		pos.x += walls.left - bRect.left;
		ReboundX();
		collided = true;
	}
	else if (bRect.right > walls.right)
	{
		pos.x -= bRect.right - walls.right;
		ReboundX();
		collided = true;
	}
	if (bRect.top < walls.top)
	{
		pos.y += walls.top - bRect.top;
		ReboundY();
		collided = true;
	}
	else if (bRect.bottom > walls.bottom)
	{
		pos.y -= bRect.bottom - walls.bottom;
		ReboundY();
		collided = true;
	}

	return collided;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

Rectf Ball::GetRect() const
{
	Vec2 center = Vec2(pos.x + 7.0f, pos.y + 7.0f);
	return Rectf::FromCenter(center, radius, radius);
}
