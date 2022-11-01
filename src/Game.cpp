#include "Game.h"
#include "TextureManager.h"
#include "PlayerCtrl.h"
#include "GameObject.h"
#include <SDL2/SDL_image.h>

typedef TextureManager TheTextureManager;
typedef PlayerCtrl ThePlayerCtrl;

// 플레이어 좌표
int PlayerX = 50;
int PlayerY = 416;

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

	if (!TheTextureManager::Instance()->load("assets/Run.png", "Run", m_pRenderer)) // 플레이어 달리기
	{
		return false;
	}

	m_background.load(0, 0, 640, 480, 0, "Background");
	m_test.load(100, 150, 32, 32, 1, "Jump");
	m_test2.load(200, 200, 32, 32, 3, "Fall");
	m_test3.load(300, 300, 32, 32, 6, "Run");
	m_player.load(PlayerX, PlayerY, 32, 32, 4, "Idle");
	m_monster.load(50, 50, 32, 32, 4, "Idle");

	m_bRunning = true;

	return true;
}

void Game::update()
{
	m_currentFrame = ((SDL_GetTicks() / 100) % 11);
	m_runFrame = ((SDL_GetTicks() / 100) % 12);

	m_test.update();
	m_test2.update();
	m_test3.update();

	m_player.update();
	m_monster.update();
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	//TheTextureManager::Instance()->draw("Background", 0, 0, 640, 480, m_pRenderer); // 배경 이미지

	//TheTextureManager::Instance()->draw("Fall", DejavuX, DejavuY, 32, 32, m_pRenderer); // 낙하 이미지

	//TheTextureManager::Instance()->drawChange("Jump", 100, 100, 32, 32, 64, 64, m_pRenderer); // 점프 이미지(크기확대)

	//TheTextureManager::Instance()->drawFrame("Idle", 50, 150, 32, 32, 0, m_currentFrame, m_pRenderer); // 플레이어 기본 이미지

	//TheTextureManager::Instance()->drawChangeFrame("Idle", PlayerX, PlayerY, 32, 32, 64, 64, 0, m_currentFrame, m_pRenderer); // 플레이어 기본 이미지(크기 확대)

	m_background.draw(m_pRenderer);
	m_test.draw(m_pRenderer);
	m_test2.drawChange(64, 64, m_pRenderer);
	m_test3.drawChangeFrame(64, 64, 0, m_runFrame, m_pRenderer);
	m_player.drawChangeFrame(64, 64, 0, m_currentFrame, m_pRenderer);
	m_monster.drawChangeFrame(64, 64, 0, m_currentFrame, m_pRenderer);

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

		// 현재 GameObject, Player, Monster 클래스를 추가하면서 값을 바뀌는데 이미지이동은 안되는 상황 
		// 원인은 PlayerX와 PlayerY가 init에서 load할 떄 한번 사용되고 update와 render에서는 GameObject, Player, Monster에 있는 m_x, m_y를 사용하기 때문으로 보임,
		case SDL_KEYDOWN: // 키보드 입력이 감지되었을 때
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT: // 왼쪽키
				PlayerX -= 3; // 플에이어의 X좌표값을 3만큼 감소
				std::cout << PlayerX << std::endl; // 바뀐 X값을 출력
				break;
			case SDLK_RIGHT: // 오른쪽키
				PlayerX += 3; // 플레이어의 X좌표값을 3만큼 증가
				std::cout << PlayerX << std::endl; // 바뀐 X값을 출력
				break;
			case SDLK_UP: // 위쪽키
				PlayerY -= 3; // 플에이어의 Y좌표값을 3만큼 갑소
				std::cout << PlayerY << std::endl; // 바뀐 Y값을 출력
				break;
			case SDLK_DOWN: // 아래쪽키
				PlayerY += 3; // 플레이어의 Y좌표값을 3만큼 증가
				std::cout << PlayerY << std::endl; // 바뀐 Y값을 출력
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