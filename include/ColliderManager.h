#pragma once
#include <Player.h>
#include <Enemy.h>

class ColliderManager
{
public:
	void set_PlayerObj(Player* player);		// 플레이어의 좌표를 받아옴
	void set_Enemy(Enemy* enemy);			// 칼의 좌표를 받아옴
	bool AABB_Coll();						// 충돌 처리 함수

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

	// 객체들의 x값과, y값을 받아옴
	struct Objects_Pos
	{
		int Player_maxX, Player_minX, Player_maxY, Player_minY;
		int Sword_MaxX, Sword_MinX, Sword_MaxY, Sword_MinY;
	}typedef ObjPos;

	Objects_Pos player_Pos;
	Objects_Pos enemy_Pos;

	//static TextureManager* s_pInstance;

}typedef TheColliderMng;

