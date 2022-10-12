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
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
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

<<<<<<< Updated upstream
=======
	// Texture 생성
	SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	// 원본상자(m_sourceRectangle)의 너비/높이 설정
	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;

	// 대상 상자(m_destinationRectangle)의 너비/높이 설정
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	// 원본상자/대상상자의 위치 설정
	m_destinationRectangle.x = 0;
	m_destinationRectangle.y = 0;

>>>>>>> Stashed changes
	m_bRunning = true;

	return true;
}

void Game::update()
{
	if (left)
	{
		m_destinationRectangle.x++;
		SDL_Delay(1);
		
		if (m_destinationRectangle.x == 357)
		{
			left = false;
			right = true;
		}
	}
	
	if (right)
	{
		m_destinationRectangle.x--;
		SDL_Delay(1);
		
		if (m_destinationRectangle.x == 0)
		{
			right = false;
			left = true;
		}
	}

	


}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
	return m_bRunning;
}

void Game::handleEvents()
{
	SDL_Event event;
<<<<<<< Updated upstream

	// 여러번의 이벤트를 실행하고자 할 때 if문으로는 실행할 수 없기 때문에
=======
>>>>>>> Stashed changes
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