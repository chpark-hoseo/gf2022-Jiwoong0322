#include "Game.h"
#include "TextureManager.h"
#include "PlayerCtrl.h"
#include "GameObject.h"
#include <SDL2/SDL_image.h>

typedef TextureManager TheTextureManager;
typedef PlayerCtrl ThePlayerCtrl;

// �÷��̾� ��ǥ
int PlayerX = 50;
int PlayerY = 416;

//// �̵� ��������Ʈ ��ǥ
//int DejavuX = 0;
//int DejavuY = 0;

bool Left = false;

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
	if (!TheTextureManager::Instance()->load("assets/Background.png", "Background", m_pRenderer)) // ���
	{
		return false;
	}


	if (!TheTextureManager::Instance()->load("assets/Idle.png", "Idle", m_pRenderer)) // �÷��̾� �⺻����
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Jump.png", "Jump", m_pRenderer)) // �÷��̾� ����
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Fall.png", "Fall", m_pRenderer)) // �÷��̾� ����
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Run.png", "Run", m_pRenderer)) // �÷��̾� �޸���
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
	m_currentFrame = ((SDL_GetTicks() / 100) % 11);
	m_runFrame = ((SDL_GetTicks() / 100) % 12);

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	for (int i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

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

		// ���� GameObject, Player, Monster Ŭ������ �߰��ϸ鼭 ���� �ٲ�µ� �̹����̵��� �ȵǴ� ��Ȳ 
		// ������ PlayerX�� PlayerY�� init���� load�� �� �ѹ� ���ǰ� update�� render������ GameObj ect, Player, Monster�� �ִ� m_x, m_y�� ����ϱ� �������� ����,
		case SDL_KEYDOWN: // Ű���� �Է��� �����Ǿ��� ��
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT: // ����Ű
				PlayerX -= 3; // �ÿ��̾��� X��ǥ���� 3��ŭ ����
				std::cout << PlayerX << std::endl; // �ٲ� X���� ���
				break;
			case SDLK_RIGHT: // ������Ű
				PlayerX += 3; // �÷��̾��� X��ǥ���� 3��ŭ ����
				std::cout << PlayerX << std::endl; // �ٲ� X���� ���
				break;
			case SDLK_UP: // ����Ű
				PlayerY -= 3; // �ÿ��̾��� Y��ǥ���� 3��ŭ ����
				std::cout << PlayerY << std::endl; // �ٲ� Y���� ���
				break;
			case SDLK_DOWN: // �Ʒ���Ű
				PlayerY += 3; // �÷��̾��� Y��ǥ���� 3��ŭ ����
				std::cout << PlayerY << std::endl; // �ٲ� Y���� ���
				break;
			//case SDLK_SPACE: // ����
			default:
				break;
			}
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