// SDL 
//
// written by changhoonpark@gmail.com


#include "main.h"
#include <SDL2/SDL.h>

SDL_Window*		g_pWindow = 0;
SDL_Renderer*	g_pRenderer = 0;

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

	// *오류 : !g_bRunning이면 g_bRunning이 false여야 하므로 g_bRunning으로 바뀌어야 함.
	// g_bRunning이 true인 동안 render함수 호출(무한루프)
	while (g_bRunning)
	{
		render();
	}

	SDL_Quit();

	return 0;
}

void update()
{

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

	SDL_RenderPresent(g_pRenderer);

	SDL_Delay(1000);
}