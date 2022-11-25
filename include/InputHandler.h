#pragma once
#include "Game.h"
#include "SDLGameObject.h"
#include <SDL2/SDL.h>

enum mouse_buttons {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler{
public:
	~InputHandler() {}
	static InputHandler* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;

	void onMouseMove(SDL_Event event);
	void onMouseButtonDown(SDL_Event event);
	void onMouseButtonUp(SDL_Event event);
	void onKeyDown();
	void onKeyUp();
	void update();
	void clean() {}

	bool isKeyDown(SDL_Scancode Key);
	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();

private:
	InputHandler();
	static InputHandler* s_pInstance;
	const Uint8* m_keystates;
};

typedef InputHandler TheInputHandler;