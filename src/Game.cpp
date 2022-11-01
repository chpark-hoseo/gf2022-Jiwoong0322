#include "Game.h"
#include "TextureManager.h"
#include "PlayerCtrl.h"
#include "GameObject.h"
#include <SDL2/SDL_image.h>

typedef TextureManager TheTextureManager;
typedef PlayerCtrl ThePlayerCtrl;

//// 플레이어 좌표
//int PlayerX = 50;
//int PlayerY = 416;
//
//// 이동 스프라이트 좌표
//int DejavuX = 0;
//int DejavuY = 0;

bool Left = false;

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
	if (!TheTextureManager::Instance()->load("assets/Background.png", "Background", m_pRenderer)) // 배경
	{
		return false;
	}


	if (!TheTextureManager::Instance()->load("assets/Idle.png", "Idle", m_pRenderer)) // 플레이어 기본상태
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Jump.png", "Jump", m_pRenderer)) // 플레이어 점프
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Fall.png", "Fall", m_pRenderer)) // 플레이어 낙하
	{
		return false;
	}

	m_player.load(100, 100, 64, 64, 4, "Idle");

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

	//TheTextureManager::Instance()->draw("Background", 0, 0, 640, 480, m_pRenderer); // 배경 이미지

	//TheTextureManager::Instance()->draw("Fall", DejavuX, DejavuY, 32, 32, m_pRenderer); // 낙하 이미지

	//TheTextureManager::Instance()->drawchange("Jump", 100, 100, 32, 32, 64, 64, m_pRenderer); // 점프 이미지(크기확대)

	//TheTextureManager::Instance()->drawFrame("Idle", 50, 150, 32, 32, 0, m_currentFrame, m_pRenderer); // 플레이어 기본 이미지

	//TheTextureManager::Instance()->drawchangeFrame("Idle", PlayerX, PlayerY, 32, 32, 64, 64, 0, m_currentFrame, m_pRenderer); // 플레이어 기본 이미지(크기 확대)

	m_player.drawFrame(0, m_currentFrame, m_pRenderer);

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

		case SDL_KEYDOWN: // 키보드 입력이 감지되었을 때
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT: // 왼쪽키
				PlayerX -= 3; // 플에이어의 X좌표값을 3만큼 감소
				break;
			case SDLK_RIGHT: // 오른쪽키
				PlayerX += 3; // 플레이어의 X좌표값을 3만큼 증가
				break;
			case SDLK_UP: // 위쪽키
				PlayerY -= 3; // 플에이어의 Y좌표값을 3만큼 갑소
				break;
			case SDLK_DOWN: // 아래쪽키
				PlayerY += 3; // 플레이어의 Y좌표값을 3만큼 증가
				break;
			//case SDLK_SPACE: // 점프
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