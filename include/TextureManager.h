#pragma once
#include <iostream> // C++ 클래스의 입출력을 위한 헤더파일
#include <map> // C++ 클래스중 map클래스를 사용하기 위한 헤더파일
#include <SDL2/SDL.h>

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

	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	/*void drawChangeFrame(std::string id, int x, int y, int width, int height, int dwidth, int dheight, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);*/
private:
	std::map<std::string, SDL_Texture*> m_textureMap;

	TextureManager() {}
	~TextureManager() {}

	static TextureManager* s_pInstance;
};

typedef TextureManager TheTextureManager;