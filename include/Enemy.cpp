#include <iostream>
#include "Game.h"
#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::drawFrame()
{
	SDLGameObject::drawFrame();
}

//void Enemy::drawChangeFrame()
//{
//
//}

void Enemy::update()
{
	handleInput();
	fall();
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);
	if (fastTime >= 0)
	{
		fastTime += 0.5;
	}
	
	if (fastTime > 10)
	{
		fastTime = 0;
		fallSpeed += 1;
	}
	/*std::cout << fastTime << std::endl;*/
	SDLGameObject::update();
}

void Enemy::fall()
{
	m_velocity.setY(fallSpeed);
}

void Enemy::handleInput()
{
	//if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	//{
	//	printf("shoot \n");
	//}
	//Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	//m_velocity = (*vec - m_position) / 100;

	//	m_velocity.setY(2);(¾Æ·¡·Î ³«ÇÏ)
}

void Enemy::clean() {}