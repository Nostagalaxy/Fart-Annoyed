#include "Bezeler.h"

Bezeler::Bezeler(Color baseColor_in)
	:
	left(0.0f),
	right(0.0f),
	top(0.0f),
	bottom(0.0f)
{
}

bool Bezeler::CheckBallCollision(const Ball& ball)
{
	Rectf rectangle(top, bottom, left, right);
	return destroyed = rectangle.IsOverlappingWith(ball.GetRect());
}

void Bezeler::DrawBrickBezel(Graphics& gfx, const Rectf& rect, Color bColor)
{
	left = rect.left + bezWidth;
	right = rect.right - bezWidth;
	top = rect.top + bezWidth;
	bottom = rect.bottom - bezWidth;

	SetBaseColor(bColor);

	//Draw Left Side of bezel
	gfx.DrawRightTriangleUR(Vec2(left, top + bezWidth), int(bezWidth), leftCol);
	gfx.DrawRect(int(left), int(top + bezWidth), int(left + bezWidth + 1), int(bottom - bezWidth), leftCol);
	gfx.DrawRightTriangleDR(Vec2(left, bottom - bezWidth), int(bezWidth), leftCol);

	//Draw Top Side
	gfx.DrawRightTriangleDL(Vec2(left + bezWidth, top), int(bezWidth), topCol);
	gfx.DrawRightTriangleDR(Vec2(right - bezWidth - 1, top), int(bezWidth), topCol);
	gfx.DrawRect(int(left + bezWidth), int(top), int(right - bezWidth), int(top + bezWidth + 1), topCol);

}

void Bezeler::SetBaseColor(Color base_in)
{
	baseColor = base_in;
	leftCol = Color(
		int( float( baseColor.GetR() ) * leftFactor),
		int( float( baseColor.GetG() ) * leftFactor),
		int( float( baseColor.GetB() ) * leftFactor));
	rightCol = Color(
		int( float( baseColor.GetR() ) * rightFactor),
		int( float( baseColor.GetG() ) * rightFactor),
		int( float( baseColor.GetB() ) * rightFactor));
	topCol = Color(
		int( float( baseColor.GetR() ) * topFactor),
		int( float( baseColor.GetG() ) * topFactor),
		int( float( baseColor.GetB() ) * topFactor));
	bottomCol = Color(
		int( float( baseColor.GetR() ) * bottomFactor),
		int( float( baseColor.GetG() ) * bottomFactor),
		int( float( baseColor.GetB() ) * bottomFactor));
}
