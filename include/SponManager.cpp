#include "SponManager.h"
#include "ColliderManager.h"
#include "LoaderParams.h"

#include "Game.h"

void SponManager::setEnemyData(Enemy* enemy)
{
	this->m_enemy = enemy;
}

void SponManager::ResponXPos(int xPos)
{
	this->respon_XPos = xPos;
}

Enemy* SponManager::Respon()
{
	if (m_enemy != NULL) {

		if (m_enemy->get_Ypos() >= TheGame::Instance()->GroundYPos)
		{
			m_enemy = NULL;
		}

		//printf("ÀÛµ¿");
	}
	else {
		Enemy* enemy = new Enemy(new LoaderParams(respon_XPos, -40, 28, 48, "Knife"));
		TheColliderMng::Instance()->set_Enemy(enemy);
		return enemy;
	}

	return NULL;
}

SponManager* SponManager::s_pInstance = 0;