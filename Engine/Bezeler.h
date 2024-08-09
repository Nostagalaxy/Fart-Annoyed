#pragma once
#include "Rectf.h"
#include "Graphics.h"
#include "Ball.h"

class Bezeler
{
public:
	Bezeler() = default;
	Bezeler(Color baseColor_in);
	bool CheckBallCollision(const Ball& ball);
	void DrawBrickBezel( Graphics& gfx,const Rectf& rect, Color bColor);
	void SetBaseColor(Color base_in);
private:

	//TODO needs to know dimensions of rect and be able to change the color for shading
	static constexpr float bezWidth = 3.0f;
	float left;
	float right;
	float top;
	float bottom;
	bool destroyed = false;

	//Shader factors
	Color baseColor;
	Color leftCol;
	Color rightCol;
	Color topCol;
	Color bottomCol;
	static constexpr float leftFactor = 0.75f;
	static constexpr float rightFactor = 0.55f;
	static constexpr float topFactor = 0.85f;
	static constexpr float bottomFactor = 0.30f;

};