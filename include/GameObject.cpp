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
	if ((m_x >= 0 || m_x < 0) && Left == false) // ���� m_x�� 0���� ũ�ų� ���� ��, Ȥ�� m_x�� 0���� ���� ��, Left�� false���
	{
		m_x += m_moveSpeed * 1; // m_x�� m_moveSpeed * 1 �� �� ��ŭ + �Ѵ�.

		if (m_x >= 356 && Left == false) // ���� m_x�� 356���� ũ�ų� ���� Left�� false���
		{
			Left = true; // Left�� true�� �Ѵ�.
		}
	}
	else if ((m_x <= 356 || m_x > 356) && Left == true) // �Ǵ� ���� m_x�� 356���� �۰ų� ���� ��, Ȥ�� m_x�� 356���� Ŭ ��, Left�� true���
	{
		m_x -= m_moveSpeed * 1; // m_x�� m_moveSpeed * 1 �� �� ��ŭ - �Ѵ�.

		if (m_x <= 0 && Left == true) // ���� m_x�� 0���� �۰ų� ���� Left�� true���
		{
			Left = false; // Left�� false�� �Ѵ�.
		}
	}

	//std::cout << m_x << std::endl; // m_x�� ���簪�� ǥ��.
	//std::cout << Left << std::endl; // Left�� ���� ���¸� ǥ��.
}