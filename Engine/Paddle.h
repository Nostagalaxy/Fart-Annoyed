#pragma once
#include "Colors.h"
#include "Ball.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle(Vec2 pos_in, float halfW, float halfH, Color c);
	void Draw(Graphics& gfx) const;
	bool DoBallCollision(Ball& b);
	void DoWallCollision(const Rectf& walls);
	void Update(const Keyboard& kbd, float dt);
	Rectf GetRect() const;
private:
	Color color;
	float halfWidth;
	float halfHeight;
	Vec2 pos;
	static constexpr float speed = 300.0f;
};