#include "Game.h"
#include "TextureManager.h"
#include <SDL2/SDL_image.h>

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

	// TextureManager.cpp에 있는 load함수를 호출.
	m_textureManager.load("assets/animate-alpha.png", "animate", m_pRenderer);

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
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);
}

//void Game::render()
//{
//	SDL_RenderClear(m_pRenderer);
//
//	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
//
//	SDL_RenderPresent(m_pRenderer);
//}

bool Game::render()
{
	m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);

	m_textureManager.drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);
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