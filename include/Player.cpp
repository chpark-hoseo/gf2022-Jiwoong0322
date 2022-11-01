#include "Player.h"

void Player::load(int x, int y, int width, int height, int moveSpeed, std::string textureID)
{
	GameObject::load(x, y, width, height, moveSpeed, textureID);
}

void Player::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}

void Player::drawChange(int dwidth, int dheight, SDL_Renderer* pRenderer)
{
	GameObject::drawChange(dwidth, dheight, pRenderer);
}

void Player::drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer)
{
	GameObject::drawFrame(currentRow, currentFrame, pRenderer);
}

void Player::drawChangeFrame(int dwidth, int dheight, int currentRow, int currentFrame, SDL_Renderer* pRenderer)
{
	GameObject::drawChangeFrame(dwidth, dheight, currentRow, currentFrame, pRenderer);
}

void Player::update()
{
	//GameObject::update();
}