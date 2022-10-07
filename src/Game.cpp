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

	// TextureManager.cpp�� �ִ� load�Լ��� ȣ��.
	m_textureManager.load("assets/animate-alpha.png", "animate", m_pRenderer);

	// �ǽ��κ�
	// ��������(m_sourceRectangle)�� �ʺ�/���� ����
	m_sourceRectangle.w = 128;
	m_sourceRectangle.h = 82;

	// �� �ڵ�� ���� ��ü�� �����ͼ� �ʺ�/���� ������ �ص� ��ü������ ���͹���
	// SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

	// ���������� ��ġ ����
	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;

	// ��� ����(m_destinationRectangle)�� �ʺ�/���� ����
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	// �������� ��ġ ����
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