#include "Game.h"
#include <SDL2/SDL_image.h>

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

	// TextureManager.cpp�� �ִ� load�Լ��� ȣ��.
	if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "monster", m_pRenderer))
	{
		return false;
	}

	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(100, 100, 128, 82, "animate")));

	m_bRunning = true;

	return true;
}

void Game::update()
{
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);

	// for���� ����Ͽ� i���� m_gameObjects.size()���� ���� ���� m_gameObjects[i]�� update�Լ��� ȣ����
	// for���� Ư���� i���� m_gameObjects.size()���� Ŀ���� �ݺ����� ���������
	// Game::update�Լ��� main.cpp���� while������ ����ؼ� �ݺ�ȣ��ǰ� �ֱ� ������ for���� �ݺ������.
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		// m_gameObjects[i]�� update�Լ��� ȣ��
		m_gameObjects[i]->update();

		// m_gameObjects[i]�� ���� �����ϱ� ���� �ڵ�. �������� �ƴ� �� ����� �ּҰ��� ��µ�
		//std::cout << m_gameObjects[i] << std::endl;
	}

	// m_gameObjects.size()�� ���� �����ϱ� ���� �ڵ�. m_gameObjects�� ����� ��Ҵ� 2���̹Ƿ� 2�� ��µ�
	//std::cout << m_gameObjects.size() << std::endl;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	// for���� ����Ͽ� i���� m_gameObjects.size()���� ���� ���� m_gameObjects[i]�� Ư�� �Լ��� ȣ����
	// for���� Ư���� i���� m_gameObjects.size()���� Ŀ���� �ݺ����� ���������
	// Game::render()�� main.cpp���� while������ ����ؼ� �ݺ�ȣ��ǰ� �ֱ� ������ for���� �ݺ������.
	for (int i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();

		// m_gameObjects[i]�� ���� �����ϱ� ���� �ڵ�.
		std::cout << m_gameObjects[i] << std::endl;
	}

	// m_gameObjects.size()�� ���� �����ϱ� ���� �ڵ�. m_gameObjects�� ����� ��Ҵ� 2���̹Ƿ� 2�� ��µ�.
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