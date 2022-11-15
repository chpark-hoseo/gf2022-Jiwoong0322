#pragma once
#include <main.h>
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Monster.h"

class Game
{
	std::vector<GameObject*> m_gameObjects;
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
	Player m_player;
	int m_currentFrame;
	int m_runFrame;
	bool m_bRunning = false;
};