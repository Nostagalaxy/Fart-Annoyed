#include "Paddle.h"
#include <cmath>

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
	gfx.DrawRect(int(p.left), int(p.top), int(p.right), int(p.bottom), wingColor);

	p.left += wingwidth;
	p.right -= wingwidth;
	gfx.DrawRect(int(p.left), int(p.top), int(p.right), int(p.bottom), color);
}

bool Paddle::DoBallCollision(Ball& b)
{
	if (b.GetVelocity().y > 0.0f && GetRect().IsOverlappingWith(b.GetRect()))
	{
		Vec2 ballCenter = b.GetCenter();
		
		if (std::signbit(b.GetVelocity().x) == std::signbit((ballCenter.x - pos.x)))
		{
			b.ReboundY();
		}
		else if (ballCenter.x <= GetRect().right &&		//Checks if ball is in between the sides of brick
			ballCenter.x >= GetRect().left)
		{
			b.ReboundY();
		}
		else
		{
			b.ReboundX();
		}

		onCooldown = true;
		return true;
	}
	return false;
}

void Paddle::DoWallCollision(const Rectf& walls)
{
	if (GetRect().left < walls.left)
	{
		pos.x += walls.left - GetRect().left;
	}
	else if (GetRect().right > walls.right)
	{
		pos.x -= GetRect().right - walls.right;
	}

}

void Paddle::Update(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= speed * dt;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += speed * dt;
	}
}

Rectf Paddle::GetRect() const
{
	return Rectf::FromCenter(pos, halfWidth, halfHeight);
}

void Paddle::resetCooldown()
{
	onCooldown = false;
}
