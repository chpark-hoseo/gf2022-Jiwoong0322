#pragma once
#include <Player.h>
#include <Enemy.h>

class ColliderManager
{
public:
	void set_PlayerObj(Player* player);		// �÷��̾��� ��ǥ�� �޾ƿ�
	void set_Enemy(Enemy* enemy);			// Į�� ��ǥ�� �޾ƿ�
	bool AABB_Coll();						// �浹 ó�� �Լ�

	void set_defaultData();

	static ColliderManager* Instance()
	{
		if (s_pInstance == NULL)
			s_pInstance = new ColliderManager();

		return s_pInstance;
	}

private:
	Player* player;
	Enemy* enemy;

	ColliderManager() = default;
	static ColliderManager* s_pInstance;

	// ��ü���� x����, y���� �޾ƿ�
	struct Objects_Pos
	{
		int Player_maxX, Player_minX, Player_maxY, Player_minY;
		int Sword_MaxX, Sword_MinX, Sword_MaxY, Sword_MinY;
	}typedef ObjPos;

	Objects_Pos player_Pos;
	Objects_Pos enemy_Pos;

	//static TextureManager* s_pInstance;

}typedef TheColliderMng;

