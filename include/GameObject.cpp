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
	// 만약 이동 스프라이트의 X좌표가 608보다 작거나 같고 Left가 false라면
	if (m_x <= 608 && Left == false)
	{
		m_x += m_moveSpeed * 1; // X좌표를 증가
		SDL_Delay(10);

		// 만약 X좌표가 608과 같다면
		if (DejavuX == 608)
		{
			Left = true; // Left를 true로 바꿈
			std::cout << "1" << std::endl; // 1을 출력
		}
	}

	// 만약 이동 스프라이트의 X좌표가 0보다 크거나 같고 Left가 true라면
	if (DejavuX >= 0 && Left == true)
	{
		DejavuX--; // X좌표를 감소
		SDL_Delay(10);

		// 만약 X좌표가 0과 같다면
		if (DejavuX == 0)
		{
			Left = false; // Left를 false로 바꿈
			std::cout << "0" << std::endl; // 0을 출력
		}
	}

// X좌표와 Left의 상태를 확인하기 위한 명령
std::cout << DejavuX << std::endl; // X좌표
std::cout << Left << std::endl; // Left상태
}