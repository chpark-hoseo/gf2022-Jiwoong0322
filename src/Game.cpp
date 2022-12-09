#include "Game.h"
#include <SDL2/SDL_image.h>

Game* Game::s_pInstance = 0;
int fireRate = 30;
int knifeNum = 0;

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
	if (!TheTextureManager::Instance()->load("assets/Background2.png", "Background", m_pRenderer))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Run.png", "Player", m_pRenderer))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Knife2.png", "Knife", m_pRenderer))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/EnemySpawner.png", "Spawner", m_pRenderer))
	{
		return false;
	}

	srand((unsigned int)time(NULL));

	m_gameObjects.push_back(new Enemy(new LoaderParams(0, 0, 480, 640, "Background")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(0, 0, 480, 64, "Spawner")));
	m_gameObjects2.push_back(new Player(new LoaderParams(0, 610, 32, 32, "Player")));
	m_gameObjects3.push_back(new Enemy(new LoaderParams(rand() % 412, 0, 28, 48, "Knife")));
	m_gameObjects3.push_back(new Enemy(new LoaderParams(rand() % 412, 0, 28, 48, "Knife")));
	m_gameObjects3.push_back(new Enemy(new LoaderParams(rand() % 412, 0, 28, 48, "Knife")));
	m_gameObjects3.push_back(new Enemy(new LoaderParams(rand() % 412, 0, 28, 48, "Knife")));
	m_gameObjects3.push_back(new Enemy(new LoaderParams(rand() % 412, 0, 28, 48, "Knife")));
	m_gameObjects3.push_back(new Enemy(new LoaderParams(rand() % 412, 0, 28, 48, "Knife")));
	m_gameObjects3.push_back(new Enemy(new LoaderParams(rand() % 412, 0, 28, 48, "Knife")));
	m_gameObjects3.push_back(new Enemy(new LoaderParams(rand() % 412, 0, 28, 48, "Knife")));
	m_gameObjects3.push_back(new Enemy(new LoaderParams(rand() % 412, 0, 28, 48, "Knife")));


	m_bRunning = true;

	return true;
}

void Game::update()
{
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);

	// for���� ����Ͽ� i���� m_gameObjects.size()���� ���� ���� m_gameObjects[i]�� update�Լ��� ȣ����
	// for���� Ư���� i���� m_gameObjects.size()���� Ŀ���� �ݺ����� ���������
	// Game::update�Լ��� main.cpp���� while������ ����ؼ� �ݺ�ȣ��ǰ� �ֱ� ������ for���� �ݺ������.
	for (int i = 0; i < m_gameObjects2.size(); i++)
	{
		// m_gameObjects[i]�� update�Լ��� ȣ��
		m_gameObjects2[i]->update();

		// m_gameObjects[i]�� ���� �����ϱ� ���� �ڵ�. �������� �ƴ� �� ����� �ּҰ��� ��µ�
		//std::cout << m_gameObjects[i] << std::endl;
	}
	
	for (int i = 0; i < m_gameObjects3.size(); i++)
	{
		m_gameObjects3[i]->update();
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

	m_gameObjects[0]->draw();
	m_gameObjects[1]->draw();
	//for (int j = 0; j != m_gameObjects.size(); j++)
	//{
	//	m_gameObjects[j]->draw();

	//	std::cout << j << std::endl;
	//}

	for (int i = 0; i != m_gameObjects2.size(); i++)
	{
		m_gameObjects2[i]->drawFrame();
	}


	
	m_gameObjects3[(SDL_GetTicks() / 1000) % 9]->draw(); // 1�ʸ��� �����׸��� �׸�
	/*knifeNum += 1;*/
	
	//for (int  i = 0; i <= fireRate; i ++)
	//{
	//	std::cout << i << " " << fireRate <<  std::endl;
	//	if (i == fireRate)
	//	{
	//		m_gameObjects3[knifeNum]->draw();
	//		knifeNum += 1;
	//		return;
	//	}
	//}

	
	/*std::cout << knifeNum << std::endl;*/
	//for (int j = 0; j != m_gameObjects3.size(); j++)
	//{
	//	m_gameObjects3[j]->draw();
	//}

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
	TheInputHandler::Instance()->update();
}

void Game::clean()
{
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}