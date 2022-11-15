#pragma once
#include <main.h>
#include <iostream>

class GameObject {
public:
	// 다형성을 갖추기 위해 부모클래스인 GameObject에 virtual추가
	// virtual을 추가하면 오류가 발생함
	virtual void load(int x, int y, int width, int height, int moveSpeed, std::string textureID);
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void drawChange(int dwidht, int dheight, SDL_Renderer* pRenderer);
	virtual void drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer);
	virtual void drawChangeFrame(int dwidth, int dheight, int currentRow, int currentFrame, SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean();

private:
	bool Left = false;

protected:
	std::string m_textureID;

	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_moveSpeed;

	int m_currentRow;
	int m_currentFrame;
};