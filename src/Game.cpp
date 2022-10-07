#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_pWindow = SDL_CreateWindow(
			title, xpos, ypos, width, height, flags
		);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{
				SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	// Texture 생성
	
	// SDL_LoadBMP : bmp 이미지파일을 로드함. bmp이외의 파일은 로드하지 못함. 기본적인 이미지 로드함수라고 생각하면 됨.
	// SDL_Surface* pTempSurface = SDL_LoadBMP("assets/animate.bmp");

	// IMG_Load : 이미지 파일을 로드함. bmp파일도 가능하며 SDL_LoadBMP함수에 여러 옵션이 붙은 것이라 이해하면 편함.
	SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	// 실습부분
	// 원본상자(m_sourceRectangle)의 너비/높이 설정
	m_sourceRectangle.w = 128;
	m_sourceRectangle.h = 82;

	// 이 코드는 파일 전체를 가져와서 너비/높이 설정을 해도 전체사진이 나와버림
	// SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

	// 원본상자의 위치 설정
	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;

	// 대상 상자(m_destinationRectangle)의 너비/높이 설정
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	// 대상상자의 위치 설정
	m_destinationRectangle.x = 0;
	m_destinationRectangle.y = 0;
	

	m_bRunning = true;

	return true;
}

void Game::update()
{
	m_sourceRectangle.x = 128 * ((SDL_GetTicks() / 100) % 6);
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);

	SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
	return m_bRunning;
}

void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}