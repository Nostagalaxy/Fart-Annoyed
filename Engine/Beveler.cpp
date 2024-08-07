#include "Beveler.h"

void Beveler::DrawBevel(Graphics& gfx) const
{


	//Draw Bezel
	
	Color bTopColor = (color.GetR(), color.GetG(), color.GetB());
	Color bLeftColor = (color.GetR(), color.GetG() + 50, color.GetB());
	//Draw Left Side of bezel
	gfx.DrawRightTriangleUR(Vec2(bezelLeft, bezelTop + bezel), int(bezel), bLeftColor);
	gfx.DrawRect(int(bezelLeft), int(bezelTop + bezel), int(bezelLeft + bezel + 1), int(bezelBottom - bezel), bLeftColor);
	gfx.DrawRightTriangleDR(Vec2(bezelLeft, bezelBottom - bezel), int(bezel), bLeftColor);
}
