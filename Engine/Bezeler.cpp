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
	gfx.DrawRightTriangleDR(Vec2(left, bottom - bezWidth - 1.0f), int(bezWidth), leftCol);

	//Draw Top Side
	gfx.DrawRightTriangleDL(Vec2(left + bezWidth, top), int(bezWidth), topCol);
	gfx.DrawRightTriangleDR(Vec2(right - bezWidth - 1, top), int(bezWidth), topCol);
	gfx.DrawRect(int(left + bezWidth), int(top), int(right - bezWidth), int(top + bezWidth + 1), topCol);

	//Draw Right Side
	gfx.DrawRightTriangleUL(Vec2(right, top + bezWidth ), int(bezWidth), rightCol);
	gfx.DrawRect(int(right - bezWidth), int(top + bezWidth), int(right + 1), int(bottom - bezWidth), rightCol);
	gfx.DrawRightTriangleDL(Vec2(right, bottom - bezWidth - 1.0f), int(bezWidth), rightCol);

	//Draw Bottom Side
	gfx.DrawRightTriangleUL(Vec2(left + bezWidth, bottom), int(bezWidth), bottomCol);
	gfx.DrawRect(int(left + bezWidth), int(bottom - bezWidth), int(right - bezWidth), int(bottom + 1.0f), bottomCol);
	gfx.DrawRightTriangleUR(Vec2(right - bezWidth, bottom), int(bezWidth), bottomCol);
}
void Bezeler::DrawInnerBezel(const Rectf& rect, Graphics& gfx, Color color)
{
	left = rect.left - frameBezHalfWidth;
	right = rect.right + frameBezHalfWidth;
	top = rect.top - frameBezHalfWidth;
	bottom = rect.bottom + frameBezHalfWidth;

	SetBaseColor(color);

	//Draw Left Side of bezel
	gfx.DrawRightTriangleUR(Vec2(left, top + frameBezHalfWidth), int(frameBezHalfWidth), leftCol);
	gfx.DrawRect(int(left), int(top + frameBezHalfWidth), int(left + frameBezHalfWidth + 1.0f), int(bottom - frameBezHalfWidth), leftCol);
	gfx.DrawRightTriangleDR(Vec2(left, bottom - frameBezHalfWidth), int(frameBezHalfWidth), leftCol);

	//Draw Top Side
	gfx.DrawRightTriangleDL(Vec2(left + frameBezHalfWidth, top), int(frameBezHalfWidth), leftCol);
	gfx.DrawRightTriangleDR(Vec2(right - frameBezHalfWidth, top), int(frameBezHalfWidth), leftCol);
	gfx.DrawRect(int(left + frameBezHalfWidth), int(top), int(right - frameBezHalfWidth), int(top + frameBezHalfWidth + 1.0f), leftCol);

	//Draw Right Side
	gfx.DrawRightTriangleUL(Vec2(right, top + frameBezHalfWidth), int(frameBezHalfWidth), rightCol);
	gfx.DrawRect(int(right - frameBezHalfWidth), int(top + frameBezHalfWidth), int(right + 1.0f), int(bottom - frameBezHalfWidth), rightCol);
	gfx.DrawRightTriangleDL(Vec2(right, bottom - frameBezHalfWidth - 1.0f), int(frameBezHalfWidth), rightCol);

	//Draw Bottom Side
	gfx.DrawRightTriangleUL(Vec2(left + frameBezHalfWidth, bottom), int(frameBezHalfWidth), bottomCol);
	gfx.DrawRect(int(left + frameBezHalfWidth), int(bottom - frameBezHalfWidth), int(right - frameBezHalfWidth), int(bottom + 1.0f), bottomCol);
	gfx.DrawRightTriangleUR(Vec2(right - frameBezHalfWidth, bottom), int(frameBezHalfWidth), bottomCol);
}

void Bezeler::DrawOuterBezel(const Rectf& rect, Graphics& gfx, Color color)
{
	left = rect.left - frBezWidth;
	right = rect.right + frBezWidth;
	top = rect.top - frBezWidth;
	bottom = rect.bottom + frBezWidth;

	SetBaseColor(color);
	
	//Draw Left Side of bezel
	gfx.DrawRightTriangleUR(Vec2(left, top + frameBezHalfWidth), int(frameBezHalfWidth), topCol);
	gfx.DrawRect(int(left), int(top + frameBezHalfWidth), int(left + frameBezHalfWidth + 1), int(bottom - frameBezHalfWidth), topCol);
	gfx.DrawRightTriangleDR(Vec2(left, bottom - frameBezHalfWidth), int(frameBezHalfWidth), topCol);

	//Draw Top Side
	gfx.DrawRightTriangleDL(Vec2(left + frameBezHalfWidth, top), int(frameBezHalfWidth), topCol);
	gfx.DrawRightTriangleDR(Vec2(right - frameBezHalfWidth, top), int(frameBezHalfWidth), topCol);
	gfx.DrawRect(int(left + frameBezHalfWidth), int(top), int(right - frameBezHalfWidth), int(top + frameBezHalfWidth + 1), topCol);

	//Draw Right Side
	gfx.DrawRightTriangleUL(Vec2(right, top + frameBezHalfWidth), int(frameBezHalfWidth), topCol);
	gfx.DrawRect(int(right - frameBezHalfWidth), int(top + frameBezHalfWidth), int(right + 1), int(bottom - frameBezHalfWidth), topCol);
	gfx.DrawRightTriangleDL(Vec2(right, bottom - frameBezHalfWidth - 1.0f), int(frameBezHalfWidth), topCol);

	//Draw Bottom Side
	gfx.DrawRightTriangleUL(Vec2(left + frameBezHalfWidth, bottom), int(frameBezHalfWidth), topCol);
	gfx.DrawRect(int(left + frameBezHalfWidth), int(bottom - frameBezHalfWidth), int(right - frameBezHalfWidth), int(bottom + 1.0f), topCol);
	gfx.DrawRightTriangleUR(Vec2(right - frameBezHalfWidth, bottom), int(frameBezHalfWidth), topCol);
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
