#pragma once
#include <main.h>
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Monster.h"
 
class Game
{
	std::vector<GameObject*> m_gameObjects; // 부모 클래스인 GameObject의 주소를 받아 멤버변수로 선언
public:
	Game() { }
	~Game() { }

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	int m_currentFrame;
	bool m_bRunning = false;
};