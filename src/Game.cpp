#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_pWindow = SDL_CreateWindow(
			title, xpos, ypos, width, height, flags
		);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	// Texture ����
	SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	// �ǽ��κ�
	/*
	// ��������(m_sourceRectangle)�� �ʺ�/���� ����
	m_sourceRectangle.w = 50;
	m_sourceRectangle.h = 50;

	// �� �ڵ�� ���� ��ü�� �����ͼ� �ʺ�/���� ������ �ص� ��ü������ ���͹���
	// SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

	// ���������� ��ġ ����
	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;

	// ��� ����(m_destinationRectangle)�� �ʺ�/���� ����
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	// �������� ��ġ ����
	m_destinationRectangle.x = 100;
	m_destinationRectangle.y = 100;
	*/

	// ���� 1 �Ӹ��κ�
	/*
	// ���� 1 �׸� �Ϻκ� �� �Ӹ��κ� ������ �������� �׸� �ʺ�/���� ����
	m_sourceRectangle.w = 50;
	m_sourceRectangle.h = 50;

	// ���� 1 �׸� �Ϻκ� �� �Ӹ��κ� ������ �������� ��ġ ����
	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;

	// ���� 1 �׸� �Ϻκ� �� �Ӹ��κ� ������ ������ �׸� �ʺ�/���� ����
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	// ���� 1 �׸� �Ϻκ� �� �Ӹ��κ� ������ ������ ��ġ ����
	m_destinationRectangle.x = 100;
	m_destinationRectangle.y = 100;
	*/

	// ���� 2 �ٸ��κ�
	/*
	// ���� 2 �׸� �Ϻκ� �� �ٸ��κ� ������ �������� �׸� �ʺ�/���� ����
	m_sourceRectangle.w = 50;
	m_sourceRectangle.h = 50;

	// ���� 2 �׸� �Ϻκ� �� �ٸ��κ� ������ �������� ��ġ ����
	m_sourceRectangle.x = 50;
	m_sourceRectangle.y = 50;

	// ���� 2 �׸� �Ϻκ� �� �ٸ��κ� ������ ������ �׸� �ʺ�/���� ����
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	// ���� 2 �׸� �Ϻκ� �� �Ӹ��κ� ������ ������ ��ġ ����
	m_destinationRectangle.x = 100;
	m_destinationRectangle.y = 100;
	*/

	// ���� 3 ��üȭ��
	/*
	// ���� 3 �׸��� ȭ�� ��ü�� ��Ÿ������ �������ϱ� �������� �׸� �ʺ�/���� ����
	m_sourceRectangle.w = 480;
	m_sourceRectangle.h = 480;

	// ���� 3 �׸��� ȭ�� ��ü�� ��Ÿ������ �������ϱ� �������� ��ġ����
	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;

	// ���� 3 �׸��� ȭ�� ��ü�� ��Ÿ������ �������ϱ� ������ �׸� �ʺ�/���� ����
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	// ���� 3 �׸��� ȭ�� ��ü�� ��Ÿ������ �������ϱ� ������ ��ġ����
	m_destinationRectangle.x = 0;
	m_destinationRectangle.y = 0;
	*/

	// ���� 4 ���������
	// ���� 3 �׸��� ȭ�� ��ü�� ��Ÿ������ �������ϱ� �������� �׸� �ʺ�/���� ����
	
	SDL_Point center;

	m_sourceRectangle.w = 150;
	m_sourceRectangle.h = 150;

	// ���� 3 �׸��� ȭ�� ��ü�� ��Ÿ������ �������ϱ� �������� ��ġ����
	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;

	// ���� 3 �׸��� ȭ�� ��ü�� ��Ÿ������ �������ϱ� ������ �׸� �ʺ�/���� ����
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	// ���� 3 �׸��� ȭ�� ��ü�� ��Ÿ������ �������ϱ� ������ ��ġ����
	m_destinationRectangle.x = 50;
	m_destinationRectangle.y = 50;

	center.x = m_sourceRectangle.x / 2;
	center.y = m_sourceRectangle.y / 2;

	SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 50, &center ,SDL_FLIP_VERTICAL);

	m_bRunning = true;

	return true;
}

void Game::update()
{
	// ���� ������ ����
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);

	SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
	return m_bRunning;
}

void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}