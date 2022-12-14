#include "SponManager.h"
#include "ColliderManager.h"
#include "LoaderParams.h"

#include "Game.h"

// 에너미의 객체정보를 받아옴
void SponManager::setEnemyData(Enemy* enemy)
{
	this->m_enemy = enemy;
}

// 새로 생성된 칼의 X좌표를 받아옴
void SponManager::ResponXPos(int xPos)
{
	this->respon_XPos = xPos;
}

// 칼을 새로 생성
Enemy* SponManager::Respon()
{
	// Null이 아니면
	if (m_enemy != NULL) {

		// 칼이 바닥과 충돌하는지 검사
		if (m_enemy->get_Ypos() >= TheGame::Instance()->GroundYPos)
		{
			m_enemy = NULL; // 충돌하면 m_enemy를 NULL로 함
		}

		//printf("작동");
	}
	// NULL이면
	else {
		// 새로운 칼 객체를 생성
		Enemy* enemy = new Enemy(new LoaderParams(respon_XPos, -40, 28, 48, "Knife"));
		TheColliderMng::Instance()->set_Enemy(enemy); // Collidermanager의 setEnemy에 새로 생성한 객체를 입력함
		return enemy; // 칼을 반환
	}

	return NULL;
}

SponManager* SponManager::s_pInstance = 0;