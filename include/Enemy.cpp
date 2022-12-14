#include <iostream>
#include "Game.h"
#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) 
	: SDLGameObject(pParams)
{}

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
		fallSpeed++;
	}
	/*std::cout << fastTime << std::endl;*/
	SDLGameObject::update();
}

// 낙하 가속도 설정
void Enemy::fall()
{
	m_acceleration.setY(fallSpeed);
}

void Enemy::handleInput()
{
	//if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	//{
	//	printf("shoot \n");
	//}
	//Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	//m_velocity = (*vec - m_position) / 100;

	//	m_velocity.setY(2);(아래로 낙하)
}

// 칼의 minX값
int Enemy::get_Xpos()
{
	return m_position.getX();
}

// 칼의 maxX값을 구하기 위한 요소
int Enemy::get_XWidth()
{
	return Width;
}

// 칼의 minY값
int Enemy::get_Ypos()
{
	return m_position.getY();
}

// 칼의 maxY값을 구하기 위한 요소
int Enemy::get_height()
{
	return height;
}

void Enemy::clean() {}