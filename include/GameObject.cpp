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
	// ���� �̵� ��������Ʈ�� X��ǥ�� 608���� �۰ų� ���� Left�� false���
	if (m_x <= 608 && Left == false)
	{
		m_x += m_moveSpeed * 1; // X��ǥ�� ����
		SDL_Delay(10);

		// ���� X��ǥ�� 608�� ���ٸ�
		if (DejavuX == 608)
		{
			Left = true; // Left�� true�� �ٲ�
			std::cout << "1" << std::endl; // 1�� ���
		}
	}

	// ���� �̵� ��������Ʈ�� X��ǥ�� 0���� ũ�ų� ���� Left�� true���
	if (DejavuX >= 0 && Left == true)
	{
		DejavuX--; // X��ǥ�� ����
		SDL_Delay(10);

		// ���� X��ǥ�� 0�� ���ٸ�
		if (DejavuX == 0)
		{
			Left = false; // Left�� false�� �ٲ�
			std::cout << "0" << std::endl; // 0�� ���
		}
	}

// X��ǥ�� Left�� ���¸� Ȯ���ϱ� ���� ���
std::cout << DejavuX << std::endl; // X��ǥ
std::cout << Left << std::endl; // Left����
}