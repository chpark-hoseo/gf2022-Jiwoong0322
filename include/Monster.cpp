#include "Monster.h"
#include <iostream>

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
	//if ((m_x >= 0 || m_x < 0) && MLeft == false)
	//{
	//	m_x += m_moveSpeed * 1;

	//	if (m_x >= 356 && MLeft == false)
	//	{
	//		MLeft = true;
	//	}
	//}
	//else if ((m_x <= 356 || m_x > 356) && MLeft == true)
	//{
	//	m_x -= m_moveSpeed * 1;
	//	
	//	if (m_x <= 0 && MLeft == true)
	//	{
	//		MLeft = false;
	//	}
	//}
	//
	//std::cout << m_x << std::endl;
	//std::cout << MLeft << std::endl;

	GameObject::update();

}