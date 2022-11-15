#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include <SDL2/SDL_image.h>

typedef TextureManager TheTextureManager;

Game* Game::s_pInstance = 0;

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

	// GameObject의 껍데기에 각각 GameObject와 Player의 실체를 가진 객체를 생성.
	GameObject* m_go = new GameObject();
	GameObject* m_player = new Player();

	// 두 객체에 (x, y)좌표, 원본상자의 크기, 이동속도, textureID를 저장함.
	m_go->load(100, 100, 128, 82, 2, "animate");
	m_player->load(300, 300, 128, 82, 4, "animate");

	// push_back은 벡터의 마지막 부분에 새로운 요소를 추가하는 함수이다.
	// m_gameObjects에 m_go와 m_player이라는 요소를 삽입.
	m_gameObjects.push_back(m_go);
	m_gameObjects.push_back(m_player);

	m_bRunning = true;

	return true;
}

void Game::update()
{
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);

	// for문을 사용하여 i값이 m_gameObjects.size()보다 작은 동안 m_gameObjects[i]의 update함수를 호출함
	// for문의 특성상 i값이 m_gameObjects.size()보다 커지면 반복문이 종료되지만
	// Game::update함수는 main.cpp에서 while문으로 계속해서 반복호출되고 있기 때문에 for문도 반복실행됨.
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		// m_gameObjects[i]의 update함수를 호출
		m_gameObjects[i]->update();

		// m_gameObjects[i]의 값을 측정하기 위한 코드. 정수값이 아닌 각 요소의 주소값이 출력됨
		//std::cout << m_gameObjects[i] << std::endl;
	}

	// m_gameObjects.size()의 값을 측정하기 위한 코드. m_gameObjects에 저장된 요소는 2개이므로 2가 출력됨
	//std::cout << m_gameObjects.size() << std::endl;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	// for문을 사용하여 i값이 m_gameObjects.size()보다 작은 동안 m_gameObjects[i]의 특정 함수를 호출함
	// for문의 특성상 i값이 m_gameObjects.size()보다 커지면 반복문이 종료되지만
	// Game::render()는 main.cpp에서 while문으로 계속해서 반복호출되고 있기 때문에 for문도 반복실행됨.
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		// m_gameObjects[i]의 drawFrame함수를 호출
		m_gameObjects[i]->drawFrame(0, m_currentFrame, m_pRenderer);

		// m_gameObjects[i]의 값을 측정하기 위한 코드. 정수값이 아닌 각 요소의 주소값이 출력됨.
		//std::cout << m_gameObjects[i] << std::endl;
	}

	// m_gameObjects.size()의 값을 측정하기 위한 코드. m_gameObjects에 저장된 요소는 2개이므로 2가 출력됨.
	//std::cout << m_gameObjects.size() << std::endl;

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