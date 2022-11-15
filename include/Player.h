#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	// Player�� �θ� Ŭ������ GameObject���� �̹� virtual�� ����Ͽ� �������� ����.
	// �ڽ� Ŭ�������� �������� �Լ��� virtual�� �����ص� ������ �����Լ��� ��.
	// ������ �ڽ� Ŭ���������� virtual�� ����ϴ��� ������. (�ڵ� ���ظ� �����ϰ� �ϱ� ���ؼ�)
	virtual void load(int x, int y, int width, int height, int moveSpeed, std::string textureID);
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void drawChange(int dwidht, int dheight, SDL_Renderer* pRenderer);
	virtual void drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer);
	virtual void drawChangeFrame(int dwidth, int dheight, int currentRow, int currentFrame, SDL_Renderer* pRenderer);
	virtual void update();
	virtual void setXY(int x, int y) { m_x = x; m_y = y; }
	virtual void clean() {};

private:
	//bool PLeft = false;
};