#pragma once
#include "Enemy.h"

class SponManager
{
public:
	void setEnemyData(Enemy* enemy);
	void ResponXPos(int xPos);
	Enemy* Respon();

	static SponManager* Instance()
	{
		if (s_pInstance == NULL)
			s_pInstance = new SponManager();

		return s_pInstance;
	}

private:
	SponManager() = default;
	static SponManager* s_pInstance;

	Enemy* m_enemy;
	int respon_XPos = 0;

	bool IsSponed = true;

}typedef TheSponMng;

