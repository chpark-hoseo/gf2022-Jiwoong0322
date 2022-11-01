#include "Monster.h"

void Monster::load(int x, int y, int width, int height, int moveSpeed, std::string textureID)
{
	GameObject::load(x, y, width, height, moveSpeed, textureID);
}

void Monster::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}

void Monster::drawChange(int dwidth, int dheight, SDL_Renderer* pRenderer)
{
	GameObject::drawChange(dwidth, dheight, pRenderer);
}

void Monster::drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer)
{
	GameObject::drawFrame(currentRow, currentFrame, pRenderer);
}

void Monster::drawChangeFrame(int dwidth, int dheight, int currentRow, int currentFrame, SDL_Renderer* pRenderer)
{
	GameObject::drawChangeFrame(dwidth, dheight, currentRow, currentFrame, pRenderer);
}

void Monster::update()
{
	//GameObject::update();

		// 만약 m_x가 0보다 크거나 같음 혹은 0보다 작을 때 Left가 false라면
	if ((m_x >= 0 || m_x < 0) && Left == false)
	{
		m_x += m_moveSpeed * 1; // m_moveSpeed * 1만큼 m_x값을 증가

		// 만약 m_x가 544보다 크거나 같고 Left가 false라면
		if (m_x >= 544 && Left == false)
		{
			Left = true; // Left를 true로 바꿈	
		}
	}
	// 또는 m_x가 544보다 작거나 같음 혹은 544보다 클 때 Left가 true라면
	else if ((m_x <= 544 || m_x > 544) && Left == true)
	{
		m_x -= m_moveSpeed * 1; // m_moveSpeed * 1만큼 m_x값을 감소

		// 만약 m_x가 0보다 작거나 같고 Left가 true라면
		if (m_x <= 0 && Left == true)
		{
			Left = false; // Left를 false로 바꿈
		}
	}

	// m_x값과 Left의 상태를 확인하기 위한 명령
	//std::cout << m_x << std::endl; // m_x의 값
	//std::cout << Left << std::endl; // Left상태
}