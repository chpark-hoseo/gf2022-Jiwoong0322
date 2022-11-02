// SDL 
//
// written by changhoonpark@gmail.com


#include "main.h"
#include <SDL2/SDL.h>

SDL_Window*		g_pWindow = 0;
SDL_Renderer*	g_pRenderer = 0;

bool g_bRunning = false;

bool init(const char* title, int xpos, int ypos, int height, int width, int flags);

int main(int argc, char* argv[])
{
	// SDL_Delay = 프로젝트를 반환하기 전에 지정된 시간(밀리초) 동안 기다림
	// 1초는 1000밀리초. 10초는 10000밀리초
	// SDL_Quit = 초기화된 모든 하위시스템을 정리함.
	SDL_Delay(10000);
	SDL_Quit();

	return 0;
}

bool init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING >= 0))
	{
		g_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
		else
		{
			return false;
		}

		SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

		return true;
	}
}

void render()
{
	SDL_RenderClear(g_pRenderer);

	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255);

	SDL_RenderPresent(g_pRenderer);
}