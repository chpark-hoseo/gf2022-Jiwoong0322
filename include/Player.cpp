#include "Player.h"
#include <iostream>

void Player::load(int x, int y, int width, int height, int moveSpeed, /*int currentRow, int currentFrame,*/ std::string textureID)
{
	GameObject::load(x, y, width, height, moveSpeed, /*currentRow, currentFrame,*/ textureID);
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
	//if ((m_x >= 0 || m_x < 0) && PLeft == false)
	//{
	//	m_x += m_moveSpeed * 1;

	//	if (m_x >= 356 && PLeft == false)
	//	{
	//		PLeft = true;
	//	}
	//}
	//else if ((m_x <= 356 || m_x > 356) && PLeft == true)
	//{
	//	m_x -= m_moveSpeed * 1;

	//	if (m_x <= 0 && PLeft == true)
	//	{
	//		PLeft = false;
	//	}
	//}

	//std::cout << m_x << std::endl;
	//std::cout << PLeft << std::endl;

	GameObject::update();
}