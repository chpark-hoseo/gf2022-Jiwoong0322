// SDL 
//
// written by changhoonpark@gmail.com


#include "main.h"
#include <SDL2/SDL.h>

SDL_Window*		g_pWindow = 0;
SDL_Renderer*	g_pRenderer = 0;


int main(int argc, char* argv[])
{
	/*if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// 윈도우 화면 생성. ""는 윈도우 이름
		// SDL_WINDOWPOS_CENTERED = 윈도우 화면의 크기
		// 정수 2개 = SDL_WINDOWPOS_CENTERED에 사용될 정수
		// SDL_WINDOW_SHOWN = 윈도우 창 표시
		
		g_pWindow = SDL_CreateWindow("Game Framework",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			1024, 768, SDL_WINDOW_SHOWN);

		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
		else
		{
			return 1;
		}
	}*/

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{

		// SDL_WINDOW_BORDERLESS = 윈도우 창 경계 없애기
		// SDL_WINDOW_MAXIMIZED = 윈도우 창 최대화
		// 이 경우 정수 2개는 윈도우 창에 표시되는 컬러 창 크기가 됨.

		g_pWindow = SDL_CreateWindow("Test3",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			300, 300, SDL_WINDOW_BORDERLESS|SDL_WINDOW_MAXIMIZED);

		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
		else
		{
			return 1;
		}
	}

	// SDL_SetRenderDrawColor = 그리기 작업에 사용될 색상 설정 (이 경우 윈도우 창)
	// SDL_RenderClear = 그려넣을 색상으로 현재 렌더링 대상을 지움
	// SDL_RenderPresent = 이전 호출 이후에 수행된 렌더링으로 화면을 업데이트 함
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255);
	SDL_RenderClear(g_pRenderer);
	SDL_RenderPresent(g_pRenderer);

	// SDL_Delay = 프로젝트를 반환하기 전에 지정된 시간(밀리초) 동안 기다림
	// 1초는 1000밀리초. 10초는 10000밀리초
	// SDL_Quit = 초기화된 모든 하위시스템을 정리함.
	SDL_Delay(10000);
	SDL_Quit();

	return 0;
}