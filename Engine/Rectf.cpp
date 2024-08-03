#include "Rectf.h"

Rectf::Rectf(float in_top, float in_bottom, float in_right, float in_left)
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
	Rectf(topleft, Vec2(width, height))
{
}

bool Rectf::IsOverlappingWith(const Rectf& other) const
{
	return top <= other.bottom &&
		bottom >= other.top &&
		left <= other.right &&
		right >= other.left;
}
