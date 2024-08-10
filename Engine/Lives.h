#pragma once
#include "Graphics.h"
#include "Rectf.h"

class Lives
{
public:
	Lives() = default;
	Lives( const Rectf& rect_in );
	void removeLife();
	void Draw(Graphics& gfx) const;
private:
	bool lifeLost;
	Rectf rect;
};