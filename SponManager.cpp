#include "SponManager.h"
#include "ColliderManager.h"
#include "Game.h"

void SponManager::setEnemyData(Enemy* enemy)
{
	this->enemy = enemy;
}

void SponManager::ResponXPos(int xPos)
{
	this->respon_XPos = xPos;
}

Enemy* SponManager::Respon()
{
	if (enemy != NULL) {

		if (enemy->get_Ypos() >= TheGame::Instance()->GroundYPos)
		{
			Enemy* enemy = new Enemy(new LoaderParams(respon_XPos, -40, 28, 48, "Knife"));
			TheColliderMng::Instance()->get_Enemy(enemy);
		}
	}
}