#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	// Player의 부모 클래스인 GameObject에서 이미 virtual을 사용하여 다형성을 가짐.
	// 자식 클래스에서 재정의한 함수는 virtual을 생략해도 저절로 가상함수가 됨.
	// 하지만 자식 클래스에서도 virtual을 사용하는이 관례임. (코드 이해를 수월하게 하기 위해서)
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