#pragma once
#include <main.h>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Monster.h"
 
class Game
{
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
	GameObject m_go;
	GameObject m_background;
	Player m_player;
	Monster m_monster;
	Monster m_test;
	Monster m_test2;
	Monster m_test3;
	int m_currentFrame;
	int m_runFrame;
	bool m_bRunning = false;
};