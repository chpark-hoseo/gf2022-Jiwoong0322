#include "Player.h"

void Player::load(int x, int y, int width, int height, int moveSpeed, std::string textureID)
{
	GameObject::load(x, y, width, height, moveSpeed, textureID);
}

void Player::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}

void Player::drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer)
{
	GameObject::drawFrame(currentRow, currentFrame, pRenderer);
}

void Player::update()
{
	GameObject::update();
}

void Player::clean()
{

}