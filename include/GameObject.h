#pragma once
#include <main.h>
#include <iostream>

class GameObject {
public:
	// �������� ���߱� ���� �θ�Ŭ������ GameObject�� virtual�߰�
	// virtual�� �߰��ϸ� ������ �߻���
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