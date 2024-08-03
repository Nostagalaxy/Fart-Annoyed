#pragma once
#include "Rectf.h"
#include "SpriteCodex.h"
#include "Graphics.h"

class Ball
{
public:
	Ball(const Vec2& pos_in, const Vec2& vel_in);
	void Draw(Graphics& gfx) const;
	void Update(const float dt);
	bool DoWallCollision(const Rectf& walls);
	void ReboundX();
	void ReboundY();

	//TODO: create function to create rect from center pos and radius (half-width, half-height)
	Rectf GetRect() const;
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
};