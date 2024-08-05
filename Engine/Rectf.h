#pragma once
#include "Vec2.h"

class Rectf
{
public:
	Rectf() = default;
	Rectf(float in_top, float in_bottom, float in_left, float in_right);
	Rectf(const Vec2& topleft, const Vec2& bottomright);
	Rectf(const Vec2& topleft, float width, float height);

	static Rectf FromCenter(const Vec2& center, float halfWidth, float halfHeight);
	bool IsOverlappingWith(const Rectf& other) const;
	Vec2 GetCenter() const;
public:
	float top;
	float bottom;
	float left;
	float right;
};