#pragma once
#include "Rectf.h"
#include "Graphics.h"

class Beveler
{
public:
	Beveler(Color& baseColor);
	void DrawBevel( Graphics& gfx ) const;
private:

	//TODO needs to know dimensions of rect and be able to change the color for shading
	float left;
	float right;
	float top;
	float bottom;

};