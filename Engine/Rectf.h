#pragma once
#include "Vec2.h"

class Rectf
{
public:
	Rectf() = default;
	Rectf(float in_top, float in_bottom, float in_left, float in_right);
	Rectf(const Vec2& topleft, const Vec2& bottomright);
	Rectf(const Vec2& topleft, float width, float height);

	bool IsOverlappingWith(const Rectf& other) const;
public:
	float top;
	float bottom;
	float left;
	float right;
};