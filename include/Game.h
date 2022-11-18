#pragma once
#include <main.h>
#include <vector>
#include "TextureManager.h"
#include "LoaderParams.h"
#include "GameObject.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Player.h"
#include "Enemy.h"


class Game
{
	std::vector<GameObject*> m_gameObjects; // 부모 클래스인 GameObject의 주소를 받아 멤버변수로 선언
public:
	static Game* Instance() {
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();
	void quit() { m_bRunning = false; }

private:
	Game() { }
	static Game* s_pInstance; // 정적 멤버변수

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	int m_currentFrame;
	bool m_bRunning = false;
};

typedef Game TheGame;