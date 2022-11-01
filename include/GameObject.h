#pragma once
#include <main.h>
#include <iostream>

class GameObject {
public:
	void load(int x, int y, int width, int height, int moveSpeed, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer);
	void update();
	void clean();

protected:
	std::string m_textureID;

	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_moveSpeed;
	int m_currentRow;
	int m_currentFrame;

	bool Left = false;
};