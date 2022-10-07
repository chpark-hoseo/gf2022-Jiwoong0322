#pragma once
#include <main.h>
#include "TextureManager.h"
 
class Game
{
public:
	Game() { }
	~Game() { }

	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	bool render();
	void update();
	bool running();
	void handleEvents();
	void clean();

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	/*SDL_Texture* m_pTexture;*/
	// 원본 사각형
	SDL_Rect m_sourceRectangle;
	// 대상 사각형
	SDL_Rect m_destinationRectangle;
	TextureManager m_textureManager;
	int m_currentFrame;
	bool m_bRunning = false;
};