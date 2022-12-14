#pragma once
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject {
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void drawFrame();
	/*virtual void drawChangeFrame();*/
	virtual void update();
	virtual void clean() {}
	virtual ~SDLGameObject() {}

	Vector2D m_velocity;
	Vector2D m_acceleration;

protected:
	Vector2D m_position;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;
};