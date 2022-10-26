#include "Game.h"
#include "TextureManager.h"
#include "PlayerCtrl.h"
#include <SDL2/SDL_image.h>

typedef TextureManager TheTextureManager;
typedef PlayerCtrl ThePlayerCtrl;

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

	// TextureManager.cpp에 있는 load함수를 호출.
	if (!TheTextureManager::Instance()->load("assets/Background.png", "Background", m_pRenderer))
	{
		return false;
	}


	if (!TheTextureManager::Instance()->load("assets/Idle.png", "Idle", m_pRenderer))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Jump.png", "Jump", m_pRenderer))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Fall.png", "Fall", m_pRenderer))
	{
		return false;
	}

	m_bRunning = true;

	return true;
}

void Game::update()
{
	m_currentFrame = ((SDL_GetTicks() / 100) % 11);
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	TheTextureManager::Instance()->draw("Background", 0, 0, 640, 480, m_pRenderer);

	TheTextureManager::Instance()->draw("Fall", 0, 0, 32, 32, m_pRenderer);

	TheTextureManager::Instance()->drawchange("Jump", 100, 100, 32, 32, 64, 64, m_pRenderer);

	TheTextureManager::Instance()->drawFrame("Idle", 50, 150, 32, 32, 0, m_currentFrame, m_pRenderer);

	TheTextureManager::Instance()->drawchangeFrame("Idle", 50, 416, 32, 32, 64, 64, 0, m_currentFrame, m_pRenderer);

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

		//case SDL_KEYDOWN:
		//	switch (event.key.keysym.sym)
		//	{
		//	case SDLK_LEFT: // 왼쪽키
		//		x--;
		//		break;
		//	case SDLK_RIGHT: // 오른쪽키
		//		x++;
		//		break;
		//	case SDLK_UP: // 위쪽키
		//		y--;
		//		break;
		//	case SDLK_DOWN: // 아래쪽키
		//		y++;
		//		break;
		//	}
		//	break;
		}
	}
}

void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}