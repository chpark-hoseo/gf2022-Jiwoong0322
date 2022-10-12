// pragma once�� �� ��������� �ߺ���������� �����̴�.
#pragma once

// ifndef�� "If not defined"�� ���ڷμ� "~�� ����(define)���� �ʾҴٸ� �̶�� �ǹ��̴�
// __Game__�� define���� �ʾҴٸ� ifndef ����
#ifndef __Game__

// #endif�� ������ ������ ���Խ��Ѷ�.
#define __Game__
#include <main.h>
class Game
{
public:
	Game() { }
	~Game() { }

	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
<<<<<<< Updated upstream
	bool m_bRunning;
};

#endif // ��
=======
	SDL_Texture* m_pTexture;
	// ���� �簢��
	SDL_Rect m_sourceRectangle;
	// ��� �簢��
	SDL_Rect m_destinationRectangle;
	bool m_bRunning = false;
	bool left = true;
	bool right = false;
};
>>>>>>> Stashed changes
