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
	m_monster2.load(200, 200, 128, 82, 1, "monster"); // Game.h에 Monster m_monster2를 추가하여 작성한 Monster::load함수호출. 정상작동. m_monster로만 몬스터 객체 2개를 만들 수 있을까?
	
	//m_monster.load(200, 200, 128, 82, 1, "animate"); // textureID를 다르게 해서 생성해본 함수호출. 위의 m_monster.load를 덮어씌우기 때문에 실패

	//Monster c_monster(m_monster); // 복사생성자. 지역변수가 아닌 전역변수로 생성해보려했으나 실패.
	//c_monster.load(200, 200, 128, 82, 1, "monster"); // 복사생성자로 작성한 함수호출. 복사생성자를 지역변수로 작성하면 오류발생이 안나기는 함. 하지만 다른 함수에서 사용을 못함.
	// 
	//m_monster.load(100, 100, 128, 82, 4, 0, m_currentFrame, "monster"); // Monster::load 함수에 currentRow와 currentFrame을 넣어 프레임 변경을 가능하게 했을 때의 실험용 코드.

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
	
	//c_monster.drawFrame(0, m_currentFrame, m_pRenderer); // 복사생성자가 전역변수로 생성되지않아 작동되지않음
	//m_monster.drawFrame(m_pRenderer); // GameObject::load 함수에 currentRow와 currentFrame을 넣어서 프레임 변경을 가능하게 했을 때의 실험용 코드

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