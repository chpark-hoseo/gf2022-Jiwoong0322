#include "GameObject.h"
#include "TextureManager.h"

typedef TextureManager TheTextureManager;

void GameObject::load(int x, int y, int width, int height, int moveSpeed, std::string textureID)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_moveSpeed = moveSpeed;
	m_textureID = textureID;
	m_currentRow = 0;
	m_currentFrame = 0;
}

void GameObject::draw(SDL_Renderer* pRenderer)
{
	TheTextureManager::Instance()
		->draw(m_textureID,
			m_x, m_y,
			m_width, m_height,
			pRenderer);
}

void GameObject::drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer)
{
	TheTextureManager::Instance()
		->drawFrame(m_textureID,
			m_x, m_y,
			m_width, m_height,
			currentRow,
			currentFrame,
			pRenderer);
}

void GameObject::update()
{
	if ((m_x >= 0 || m_x < 0) && Left == false) // 만약 m_x가 0보다 크거나 같을 때, 혹은 m_x가 0보다 작을 때, Left가 false라면
	{
		m_x += m_moveSpeed * 1; // m_x를 m_moveSpeed * 1 한 값 만큼 + 한다.

		if (m_x >= 356 && Left == false) // 만약 m_x가 356보다 크거나 같고 Left가 false라면
		{
			Left = true; // Left를 true로 한다.
		}
	}
	else if ((m_x <= 356 || m_x > 356) && Left == true) // 또는 만약 m_x가 356보다 작거나 같을 때, 혹은 m_x가 356보다 클 때, Left가 true라면
	{
		m_x -= m_moveSpeed * 1; // m_x를 m_moveSpeed * 1 한 값 만큼 - 한다.

		if (m_x <= 0 && Left == true) // 만약 m_x가 0보다 작거나 같고 Left가 true라면
		{
			Left = false; // Left를 false로 한다.
		}
	}

	//std::cout << m_x << std::endl; // m_x의 현재값을 표시.
	//std::cout << Left << std::endl; // Left의 현재 상태를 표시.
}