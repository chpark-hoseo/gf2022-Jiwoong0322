#include "Game.h"
#include "TextureManager.h"
#include <SDL2/SDL_image.h>

typedef TextureManager TheTextureManager;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
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
	if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "monster", m_pRenderer))
	{
		return false;
	}

	//m_go.load(200, 200, 128, 82, 1, "animate");
	//m_player.load(300, 300, 128, 82, 1, "animate");
	m_monster.load(100, 100, 128, 82, 10, "monster");
	m_monster2.load(200, 200, 128, 82, 1, "monster"); // Game.h에 Monster m_monster2를 추가하여 작성한 Monster::load함수호출.

	m_bRunning = true;

	return true;
}

void Game::update()
{
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);

	m_go.update();
	m_player.update();
	m_monster.update();
	m_monster2.update(); // m_monster2의 Monster::update 함수호출
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	//TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);

	//TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);

	//m_go.draw(m_pRenderer);
	//m_player.draw(m_pRenderer);
	m_monster.drawFrame(0, m_currentFrame, m_pRenderer);
	m_monster2.drawFrame(0, m_currentFrame, m_pRenderer); // m_monster2의 Monster::drawFrame 함수호출

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