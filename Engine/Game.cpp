/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(300.0f, 400.0f), Vec2(300.0f, 300.0f)),
	walls(0.0f, float(gfx.ScreenHeight), 0.0f, float(gfx.ScreenWidth)),
	ballSound(L"Sounds\\arkpad.wav"),
	brickPad(L"Sounds\\arkbrick.wav"),
	paddle(Vec2(400.0f, 550.0f), 30.0f, 10.0f, Colors::White)
{
	//Add color array to set colors for each row
	const Color color[numBricksDown] = { Colors::Blue, Colors::Green, Colors::Yellow, Colors::Red, Colors::Magenta };

	const Vec2 topleft(40.0f, 40.0f);

	int i = 0;

	//For loop to construct each brick in array
	//row
	for (int y = 0; y < numBricksDown; y++)
	{
		for (int x = 0; x < numBricksAcross; x++)
		{
			//screen_x = grid_x * width
			bricks[i] = Brick(Rectf(topleft + Vec2(x * brickWidth, y * brickHeight), brickWidth, brickHeight), color[y]);
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0.0f)
	{
		const float dt = std::min(0.0025f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel( float dt)
{
	ball.Update( dt );
	
	paddle.Update(wnd.kbd, dt);
	paddle.DoWallCollision(walls);
	
	bool collisionHappened = false;
	float curColDist;
	int curColIndex;

	if (paddle.DoBallCollision(ball))
	{
		ballSound.Play();
	}

	for (int i = 0; i < numBricks; i++)
	{
		if (bricks[i].CheckBallCollision(ball))
		{
			float newColDist = (ball.GetCenter() - bricks[i].GetCenter()).GetLengthSq();
			if (collisionHappened)
			{
				if (newColDist < curColDist)
				{
					curColDist = newColDist;
					curColIndex = i;
				}
			}
			else 
			{
				curColDist = newColDist;
				curColIndex = i;
				collisionHappened = true;
			}
		}
	}

	if (collisionHappened)
	{
		paddle.resetCooldown();
		bricks[curColIndex].ExecuteBallCollision( ball );
		brickPad.Play();
	}

	if (ball.DoWallCollision(walls))
	{
		paddle.resetCooldown();
		ballSound.Play();
	}
}

void Game::ComposeFrame()
{
	ball.Draw( gfx );
	//ranged based for loop
	for (const Brick& b : bricks)
	{
		b.Draw( gfx );
	}
	paddle.Draw( gfx );
}
