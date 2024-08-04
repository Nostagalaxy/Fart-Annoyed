#include "Paddle.h"

Paddle::Paddle(Vec2 pos_in, float halfW, float halfH, Color c)
{
	pos = pos_in;
	halfWidth = halfW;
	halfHeight = halfH;
	color = c;
}

void Paddle::Draw(Graphics& gfx) const
{
	Rectf p = GetRect();
	gfx.DrawRect(int(p.left), int(p.top), int(p.right), int(p.bottom), color);
}

bool Paddle::DoBallCollision(Ball& b)
{
	return false;
}

bool Paddle::DoWallCollision(Rectf& walls)
{
	return false;
}

void Paddle::Update(Keyboard& kbd, float dt)
{
}

Rectf Paddle::GetRect() const
{
	return Rectf::FromCenter(pos, halfWidth, halfHeight);
}
