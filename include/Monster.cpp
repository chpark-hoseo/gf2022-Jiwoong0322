#include "Monster.h"

void Monster::load(int x, int y, int width, int height, int moveSpeed, std::string textureID)
{
	GameObject::load(x, y, width, height, moveSpeed, textureID);
}

void Monster::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}

void Monster::drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer)
{
	GameObject::drawFrame(currentRow, currentFrame, pRenderer);
}

void Monster::update()
{
	GameObject::update();
}

void Monster::clean()
{
	
}