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
	handleInput();
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);
	SDLGameObject::update();
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
	static int push = 0;
	if (m_keystates != 0) {
		if (m_keystates[key] == 1)
		{
			if (push == 2)
			{
				return false;
			}
			else
			{
				return ++push;
			}
		}
		else
		{
			push = 0;
			return false;
		}
	}
	return false;
}
// 실습완료

void Player::clean() {}