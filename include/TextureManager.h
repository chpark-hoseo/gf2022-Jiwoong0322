#pragma once
#include <iostream> // C++ Ŭ������ ������� ���� �������
#include <map> // C++ Ŭ������ mapŬ������ ����ϱ� ���� �������

class TextureManager
{
public:
	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
		}

		return s_pInstance;
	}

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	// �̹��� ������ �׸��� �Լ�
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// �̹��� ������ �����ϰ��� �� �� ũ�� ������ �ʿ��ϸ� �� �Լ��� ���. swidth, sheight�� ���������� ũ��, dwidth, dheight�� �������� ũ��.
	void drawchange(std::string id, int x, int y, int swidth, int sheight, int dwidth, int dheight, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// �����̴� �̹��� ������ �׸��� �Լ�
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// �����̴� �̹��� ������ �����ϰ��� �� �� ũ�� ������ �ʿ��ϸ� �� �Լ��� ���. swidth, sheight�� ���������� ũ��, dwidth, dheight�� �������� ũ��.
	void drawchangeFrame(std::string id, int x, int y, int swidth, int sheight, int dwidth, int dheight, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	std::map<std::string, SDL_Texture*> m_textureMap;

	TextureManager() {}
	~TextureManager() {}

	static TextureManager* s_pInstance;
};