#include "Rectf.h"

Rectf::Rectf(float in_top, float in_bottom, float in_left, float in_right)
	:
	top(in_top),
	bottom(in_bottom),
	left(in_left),
	right(in_right)
{
}

Rectf::Rectf(const Vec2& topleft, const Vec2& bottomright)
	:
	Rectf(top = topleft.y, bottom = bottomright.y, left = topleft.x, right = bottomright.x)
{
}

Rectf::Rectf(const Vec2& topleft, float width, float height)
	:
	Rectf(topleft, Vec2(topleft.x + width, topleft.y + height))
{
}

Rectf Rectf::FromCenter(const Vec2& center, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);

	return Rectf(center - half, center + half);
}

bool Rectf::IsOverlappingWith(const Rectf& other) const
{
	return top <= other.bottom &&
		bottom >= other.top &&
		left <= other.right &&
		right >= other.left;
}

Vec2 Rectf::GetCenter() const
{
	const float x = (right + left) / 2.0f;
	const float y = (bottom + top) / 2.0f;
	return Vec2(x, y);
}
