#pragma once
#include <iostream>
#include "LoaderParams.h"

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void drawFrame() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

	virtual ~GameObject() { }
	
private:
	bool Left = false;

protected:
	//std::string m_textureID;

	GameObject(const LoaderParams* pParams) { }

	/*int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_moveSpeed;

	int m_currentFrame;
	int m_currentRow;*/
};