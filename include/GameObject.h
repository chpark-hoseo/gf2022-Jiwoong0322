#pragma once
#include <main.h>
#include <iostream>

class GameObject {
public:
	// 함수호출 인수에 moveSpeed를 추가. 이동속도 변경을 가능하게 함.
	// load함수 안에 currentRow와 currentFrame을 넣어도 이미지가 움직이지 않음. 왜?
	void load(int x, int y, int width, int height, int moveSpeed, /*int currentRow, int currentFrame,*/ std::string textureID);

	void draw(SDL_Renderer* pRenderer);
	void drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer); // 함수호출 인수에 currentRow, currentFrame을 추가. 프레임 변경을 가능하게 함.
	void update();

	void clean();
	
private:
	bool Left = false;

protected:
	std::string m_textureID;

	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_moveSpeed;

	int m_currentFrame;
	int m_currentRow;
};