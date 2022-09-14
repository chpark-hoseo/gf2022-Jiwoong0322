// SDL 
//
// written by changhoonpark@gmail.com


#include "main.h"
#include <SDL2/SDL.h>


SDL_Window*		g_pWindow = 0;
SDL_Renderer*	g_pRenderer = 0;

SDL_Texture*	g_pTexureImage;
SDL_Rect		g_RectImage;

SDL_Texture*	g_pTexureText;
SDL_Rect 		g_RectText;

TTF_Font*		g_pFont;
Mix_Chunk*		g_pChunk;

bool			g_bRunning = false;
bool			g_bLeftMousePressed = false;

//bool init();
//void handleInput();
//void update();
//void render();

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

//bool init()
//{
//	SDL_Surface* pTempSurface;
//
//	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
//	{
//		SDL_Log("SDL_Init Error: %s\n", SDL_GetError());
//		return false;
//	}
//
//	g_pWindow = SDL_CreateWindow("HoseoSDL.2022",
//		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//		640, 480, SDL_WINDOW_SHOWN);
//	if (g_pWindow == NULL)
//	{
//		SDL_Log("SDL_CreateWindow Error: %s\n", SDL_GetError());
//		return false;
//	}
//
//	g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
//	if (g_pRenderer == NULL)
//	{
//		SDL_Log("SDL_CreateRenderer Error: %s\n", SDL_GetError());
//		return false;
//	}
//	else
//	{
//		// SDL Image
//		pTempSurface = IMG_Load("./assets/animate-alpha.png");
//		if (pTempSurface == NULL)
//		{
//			SDL_Log("IMG_Load Error: %s\n", IMG_GetError());
//			return false;
//		}
//		else
//		{
//			g_pTexureImage = SDL_CreateTextureFromSurface(g_pRenderer, pTempSurface);
//			g_RectImage = { 0, 0, 128, 82 };
//			SDL_FreeSurface(pTempSurface);
//		}
//	}
//
//	// SDL TTF 
//	if (TTF_Init() < 0)
//	{
//		SDL_Log("TTF_Init Error: %s\n", TTF_GetError());
//		return false;
//	}
//	else
//	{
//		g_pFont = TTF_OpenFont("./assets/NanumGothic.ttf", 20);
//		if (g_pFont == NULL)
//		{
//			SDL_Log("TTF_OpenFont Error: %s\n", TTF_GetError());
//			return false;
//		}
//		else
//		{
//			// SDL TTF
//#ifdef UNICODE
//			pTempSurface = TTF_RenderUNICODE_Shaded(g_pFont, (Uint16*)L"한글 텍스쳐",
//				SDL_Color{ 0, 0, 255 }, SDL_Color{ 255, 255, 255 });
//#else
//			pTempSurface = TTF_RenderUTF8_Shaded(g_pFont, "한글 텍스쳐",
//				SDL_Color{ 0, 0, 255 }, SDL_Color{ 255, 255, 255 });
//#endif
//			if (pTempSurface == NULL)
//			{
//				SDL_Log("TTF_Render Error: %s\n", TTF_GetError());
//				return false;
//			}
//			else
//			{
//				g_pTexureText = SDL_CreateTextureFromSurface(g_pRenderer, pTempSurface);
//				g_RectText = { 0, 0, pTempSurface->w, pTempSurface->h };
//				SDL_FreeSurface(pTempSurface);
//			}
//		}
//
//	}
//
//	// SDL Mixer 
//	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
//	{
//		SDL_Log("Mix_OpenAudio Error: %s\n", Mix_GetError());
//		return false;
//	}
//	else
//	{
//		g_pChunk = Mix_LoadWAV("./assets/jump.wav");
//		if (g_pChunk == NULL)
//		{
//			SDL_Log("Mix_LoadWAV Error : %s\n", Mix_GetError());
//			return false;
//		}
//		else
//		{
//			Mix_Volume(-1, 128);
//		}
//	}
//
//	return true;
//}
//
//void handleInput()
//{
//	SDL_Event event;
//	while (SDL_PollEvent(&event))
//	{
//		switch (event.type)
//		{
//		case SDL_QUIT:
//			g_bRunning = false;
//			break;
//
//		case SDL_MOUSEBUTTONDOWN:
//			if (event.button.button == SDL_BUTTON_LEFT)
//			{
//				g_bLeftMousePressed = true;
//			}
//			break;
//
//		case SDL_MOUSEBUTTONUP:
//			if (event.button.button == SDL_BUTTON_LEFT)
//			{
//				g_bLeftMousePressed = false;
//			}
//			break;
//
//		}
//	}
//}
//
//void update()
//{
//	if (g_bLeftMousePressed)
//	{
//		// chunk에 담긴 사운드 재생, -1은 가장 가까운 채널, 0은 반복 횟수
//		Mix_PlayChannel(-1, g_pChunk, 0);
//		printf("왼쪽클릭 눌림 - 사운드 재생\n");
//	}
//}
//
//void render()
//{
//	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
//	SDL_RenderClear(g_pRenderer);
//
//	SDL_RenderCopy(g_pRenderer, g_pTexureImage, &g_RectImage, &g_RectImage);
//	SDL_RenderCopy(g_pRenderer, g_pTexureText, &g_RectText, &g_RectText);
//	filledCircleColor(g_pRenderer, 300, 300, 50, 0xFFFF0000);
//
//	SDL_RenderPresent(g_pRenderer);
//}