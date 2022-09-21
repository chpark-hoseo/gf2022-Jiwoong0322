﻿// SDL 
//
// written by changhoonpark@gmail.com


#include "main.h"
#include <SDL2/SDL.h>

SDL_Window*		g_pWindow = 0;
SDL_Renderer*	g_pRenderer = 0;

int count = 0;

bool g_bRunning = false;

bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
void update();
void render();

int main(int argc, char* argv[])
{
	if (init("Breaking Up HelloSDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN))
	{
		g_bRunning = true;
	}
	else
	{
		return 1;
	}

	
	while (g_bRunning)
	{
		update();
		render();
	}

	SDL_Quit();

	return 0;
}

void update()
{
	// 카운트가 5 이상이 되면 g_bRunning을 false로 변경
	if (count >= 5)
	{
		g_bRunning = false;
	}
}

bool init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	}
	else
	{
		return false;
	}

	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

	return true;
}

void render()
{
	SDL_RenderClear(g_pRenderer);

	// 색깔 랜덤 바꾸기
	SDL_SetRenderDrawColor(g_pRenderer, rand() % 256, rand() % 256, rand() % 256, 255);
	// 색깔이 한번 바뀔 때 마다 count 1 추가
	count++;

	SDL_RenderPresent(g_pRenderer);

	SDL_Delay(1000);
}