#pragma once

#include <SDL2/SDL.h>
#include <iostream> // C++ Ŭ������ ������� ���� �������
#include <map> // C++ Ŭ������ mapŬ������ ����ϱ� ���� �������

class TextureManager
{
public:
	TextureManager() {}
	~TextureManager() {}

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	std::map<std::string, SDL_Texture*> m_textureMap;
};