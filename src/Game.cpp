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
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
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
	SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	// 실습부분
	/*
	// 원본상자(m_sourceRectangle)의 너비/높이 설정
	m_sourceRectangle.w = 50;
	m_sourceRectangle.h = 50;

	// 이 코드는 파일 전체를 가져와서 너비/높이 설정을 해도 전체사진이 나와버림
	// SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

	// 원본상자의 위치 설정
	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;

	// 대상 상자(m_destinationRectangle)의 너비/높이 설정
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	// 대상상자의 위치 설정
	m_destinationRectangle.x = 100;
	m_destinationRectangle.y = 100;
	*/

	// 과제 1 머리부분
	/*
	// 과제 1 그림 일부분 중 머리부분 랜더링 원본상자 그림 너비/높이 설정
	m_sourceRectangle.w = 50;
	m_sourceRectangle.h = 50;

	// 과제 1 그림 일부분 중 머리부분 랜더링 원본상자 위치 설정
	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;

	// 과제 1 그림 일부분 중 머리부분 랜더링 대상상자 그림 너비/높이 설정
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	// 과제 1 그림 일부분 중 머리부분 랜더링 대상상자 위치 설정
	m_destinationRectangle.x = 100;
	m_destinationRectangle.y = 100;
	*/

	// 과제 2 다리부분
	/*
	// 과제 2 그림 일부분 중 다리부분 랜더링 원본상자 그림 너비/높이 설정
	m_sourceRectangle.w = 50;
	m_sourceRectangle.h = 50;

	// 과제 2 그림 일부분 중 다리부분 랜더링 원본상자 위치 설정
	m_sourceRectangle.x = 50;
	m_sourceRectangle.y = 50;

	// 과제 2 그림 일부분 중 다리부분 랜더링 대상상자 그림 너비/높이 설정
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	// 과제 2 그림 일부분 중 머리부분 랜더링 대상상자 위치 설정
	m_destinationRectangle.x = 100;
	m_destinationRectangle.y = 100;
	*/

	// 과제 3 전체화면
	/*
	// 과제 3 그림이 화면 전체에 나타나도록 렌더링하기 원본상자 그림 너비/높이 설정
	m_sourceRectangle.w = 480;
	m_sourceRectangle.h = 480;

	// 과제 3 그림이 화면 전체에 나타나도록 렌더링하기 원본상자 위치설정
	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;

	// 과제 3 그림이 화면 전체에 나타나도록 렌더링하기 대상상자 그림 너비/높이 설정
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	// 과제 3 그림이 화면 전체에 나타나도록 렌더링하기 대상상자 위치설정
	m_destinationRectangle.x = 0;
	m_destinationRectangle.y = 0;
	*/

	// 과제 4 예제만들기
	// 과제 3 그림이 화면 전체에 나타나도록 렌더링하기 원본상자 그림 너비/높이 설정
	
	SDL_Point center;

	m_sourceRectangle.w = 150;
	m_sourceRectangle.h = 150;

	// 과제 3 그림이 화면 전체에 나타나도록 렌더링하기 원본상자 위치설정
	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;

	// 과제 3 그림이 화면 전체에 나타나도록 렌더링하기 대상상자 그림 너비/높이 설정
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	// 과제 3 그림이 화면 전체에 나타나도록 렌더링하기 대상상자 위치설정
	m_destinationRectangle.x = 50;
	m_destinationRectangle.y = 50;

	center.x = m_sourceRectangle.x / 2;
	center.y = m_sourceRectangle.y / 2;

	SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 50, &center ,SDL_FLIP_VERTICAL);

	m_bRunning = true;

	return true;
}

void Game::update()
{
	// 게임 데이터 갱신
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