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

		// ���� m_x�� 0���� ũ�ų� ���� Ȥ�� 0���� ���� �� Left�� false���
	if ((m_x >= 0 || m_x < 0) && Left == false)
	{
		m_x += m_moveSpeed * 1; // m_moveSpeed * 1��ŭ m_x���� ����

		// ���� m_x�� 544���� ũ�ų� ���� Left�� false���
		if (m_x >= 544 && Left == false)
		{
			Left = true; // Left�� true�� �ٲ�	
		}
	}
	// �Ǵ� m_x�� 544���� �۰ų� ���� Ȥ�� 544���� Ŭ �� Left�� true���
	else if ((m_x <= 544 || m_x > 544) && Left == true)
	{
		m_x -= m_moveSpeed * 1; // m_moveSpeed * 1��ŭ m_x���� ����

		// ���� m_x�� 0���� �۰ų� ���� Left�� true���
		if (m_x <= 0 && Left == true)
		{
			Left = false; // Left�� false�� �ٲ�
		}
	}

	// m_x���� Left�� ���¸� Ȯ���ϱ� ���� ���
	//std::cout << m_x << std::endl; // m_x�� ��
	//std::cout << Left << std::endl; // Left����
}