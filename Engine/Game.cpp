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
	ball(Vec2(100.0f, 100.0f), Vec2(300.0f, 300.0f)),
	walls(0.0f, float(gfx.ScreenHeight), 0.0f, float(gfx.ScreenWidth)),
	ballSound(L"Sounds\\arkpad.wav"),
	brickPad(L"Sounds\\arkbrick.wav"),
	brick (Rectf(Vec2(200.0f, 200.0f), 50.0f, 20.0f), Colors::Cyan),
	paddle(Vec2(400.0f, 550.0f), 30.0f, 10.0f, Colors::White)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float dt = ft.Mark();
	ball.Update( dt );
	paddle.Update(wnd.kbd, dt);
	paddle.DoWallCollision(walls);
	if (paddle.DoBallCollision(ball))
	{
		ballSound.Play();
	}

	if (brick.DoBallCollision(ball))
	{
		brickPad.Play();
	}

	if (ball.DoWallCollision(walls))
	{
		ballSound.Play();
	}
}

void Game::ComposeFrame()
{
	ball.Draw( gfx );
	brick.Draw( gfx );
	paddle.Draw( gfx );
}
