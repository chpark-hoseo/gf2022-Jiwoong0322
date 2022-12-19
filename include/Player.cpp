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
	// Hp가 0보다 크면
	if (Hp > 0) {
		// IsColl이 false가 아니면
		if (!IsColl) {
			handleInput(); // handleInput 호출
			m_currentFrame = ((SDL_GetTicks()  / 100) % 12); // m_currentFrame 실행
		}
		// 그외에는
		else
		{
			m_velocity.setX(0); // 플레이어의 이동을 제한
			delayCnt++; // 경직시간 증가

			// 경직 시간이 최대경직시간보다 길면
			if (delayCnt >= delayTime) {
				IsColl = false; // IsColl을 false로 변경
				delayCnt = 0;
			}

			//printf("%d\n", delayCnt);
		}
	}
	// hp가 0보다 작아지면
	else {
		m_velocity.setX(0); // 플레이어의 이동을 제한
	}

	SDLGameObject::update();
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		// 플레이어의 X좌표애 width를 더한만큼의 값이 ScreenWidth값 이상으로 진행하지 못하도록 막음
		if (m_position.getX() + width >= TheGame::Instance()->ScreenWidth)
			m_velocity.setX(0);
		// 그외에는 이동 가능
		else
			m_velocity.setX(4);
	}

	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		// 플레이어의 x좌표값이 0보다 크면 이동가능하도록 함
		if(m_position.getX() > 0)
			m_velocity.setX(-4);
		// 그외에는 이동 불가
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
	if (IsColl)
	{
		Hp--;
	}

	printf("%d \n", Hp);
}

void Player::clean() {}