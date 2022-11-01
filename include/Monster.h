#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
public:
	void load(int x, int y, int width, int height, int moveSpeed, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void drawChange(int dwidth, int dheight, SDL_Renderer* pRenderer);
	void drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer);
	void drawChangeFrame(int dwidth, int dheight, int currentRow, int currentFrame, SDL_Renderer* pRenderer);
	void update();
	void clean() {};

private:
	//bool MLeft = false;
};