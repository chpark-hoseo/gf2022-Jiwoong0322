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

void GameObject::drawChange(int dwidth, int dheight, SDL_Renderer* pRenderer)
{
	TheTextureManager::Instance()
		->drawChange(m_textureID,
			m_x, m_y,
			m_width, m_height,
			dwidth, dheight,
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

void GameObject::drawChangeFrame(int dwidth, int dheight, int currentRow, int currentFrame, SDL_Renderer* pRenderer)
{
	TheTextureManager::Instance()
		->drawChangeFrame(m_textureID,
			m_x, m_y,
			m_width, m_height,
			dwidth, dheight,
			currentRow,
			currentFrame,
			pRenderer);
}

void GameObject::update()
{

}