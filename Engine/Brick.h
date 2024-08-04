#pragma once
#include "Rectf.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick(const Rectf& rect, const Color& color);
	void Draw(Graphics& gfx) const;
	bool DoBallCollision(Ball& ball);
private:
	Rectf rect;
	Color color;
	bool destroyed = false;
};