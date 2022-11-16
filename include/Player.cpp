#include <iostream>
#include "Player.h"
#include "Game.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	SDLGameObject::update();
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);
}

void Player::clean() {}