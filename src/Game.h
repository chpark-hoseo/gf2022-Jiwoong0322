// pragma once는 이 헤더파일을 중복하지말라는 선언이다.
#pragma once

// ifndef는 "If not defined"의 약자로서 "~을 정의(define)하지 않았다면 이라는 의미이다
// __Game__을 define하지 않았다면 ifndef 실행
#ifndef __Game__

// #endif가 나오기 전까지 포함시켜라.
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
	bool m_bRunning;
};

#endif // 끝