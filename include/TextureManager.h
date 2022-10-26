#pragma once
#include <iostream> // C++ 클래스의 입출력을 위한 헤더파일
#include <map> // C++ 클래스중 map클래스를 사용하기 위한 헤더파일

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

	// 이미지 파일을 그리는 함수
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// 이미지 파일을 생성하고자 할 때 크기 변경이 필요하면 이 함수를 사용. swidth, sheight는 원본상자의 크기, dwidth, dheight는 대상상자의 크기.
	void drawchange(std::string id, int x, int y, int swidth, int sheight, int dwidth, int dheight, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// 움직이는 이미지 파일을 그리는 함수
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// 움직이는 이미지 파일을 생성하고자 할 떄 크기 변경이 필요하면 이 함수를 사용. swidth, sheight는 원본상자의 크기, dwidth, dheight는 대상상자의 크기.
	void drawchangeFrame(std::string id, int x, int y, int swidth, int sheight, int dwidth, int dheight, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	std::map<std::string, SDL_Texture*> m_textureMap;

	TextureManager() {}
	~TextureManager() {}

	static TextureManager* s_pInstance;
};