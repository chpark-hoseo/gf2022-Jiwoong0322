#pragma once
#include <main.h>
#include <iostream>

class GameObject {
public:
	// �Լ�ȣ�� �μ��� moveSpeed�� �߰�. �̵��ӵ� ������ �����ϰ� ��.
	// load�Լ� �ȿ� currentRow�� currentFrame�� �־ �̹����� �������� ����. ��?
	void load(int x, int y, int width, int height, int moveSpeed, /*int currentRow, int currentFrame,*/ std::string textureID);

	void draw(SDL_Renderer* pRenderer);
	void drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer); // �Լ�ȣ�� �μ��� currentRow, currentFrame�� �߰�. ������ ������ �����ϰ� ��.
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