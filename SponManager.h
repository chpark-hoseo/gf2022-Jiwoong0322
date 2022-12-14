#pragma once
#include "Enemy.h"

class SponManager
{
public:
	void setEnemyData(Enemy* enemy);
	void ResponXPos(int xPos);
	Enemy* Respon();

private:
	Enemy* enemy;
	int respon_XPos = 0;
};

