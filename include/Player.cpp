#include <iostream>
#include "Player.h"
#include "Game.h"
#include <iostream>

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::drawFrame()
{
	SDLGameObject::drawFrame();
}

void Player::update()
{
	if (Hp > 0) {
		if (!IsColl) {
			handleInput();
			m_currentFrame = ((SDL_GetTicks() / 100) % 12);
		}
		else {
			m_velocity.setX(0);
			delayCnt++;

			if (delayCnt >= delayTime) {
				IsColl = false;
			}

			//printf("%d\n", delayCnt);
		}
	}
	else {
		m_velocity.setX(0);
	}

	SDLGameObject::update();
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		if (m_position.getX() + width >= TheGame::Instance()->ScreenWidth)
			m_velocity.setX(0);
		else
			m_velocity.setX(4);
	}

	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		if(m_position.getX() > 0)
			m_velocity.setX(-4);
		else
			m_velocity.setX(0);
	}

	else
		m_velocity.setX(0);

	//if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	//{
	//	m_velocity.setY(0);
	//}
	//if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	//{
	//	m_velocity.setY(2);
	//}
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

int Player::get_XPos()
{
	return m_position.getX();
}
int Player::get_XWidth()
{
	return width;
}
int Player::get_YPos()
{
	return m_position.getY();
}
int Player::get_height()
{
	return height;
}

void Player::set_IsColl(bool IsColl)
{
	this->IsColl = IsColl;
	if(IsColl)
		Hp--;

	printf("%d \n", Hp);
}

void Player::clean() {}