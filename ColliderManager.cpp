#include "ColliderManager.h"

void ColliderManager::get_PlayerObj(Player* player)
{
	player_Pos.Player_minX = player->get_XPos();
	player_Pos.Player_maxX = player->get_XPos() + player->get_XWidth();

	player_Pos.Player_minY = player->get_YPos() - player->get_YWidth();
}

void ColliderManager::get_Enemy(Enemy* enemy)
{
	enemy_Pos.Sword_MinX = enemy->get_Xpos();
	enemy_Pos.Sword_MaxX = enemy->get_Xpos() + enemy->get_XWidth();

	enemy_Pos.Sword_MaxY = enemy->get_Ypos();
}

bool ColliderManager::AABB_Coll()
{
	if (player_Pos.Player_maxX >= enemy_Pos.Sword_MinX &&
		player_Pos.Player_minX <= enemy_Pos.Sword_MinX) {

		if (player_Pos.Player_minY <= enemy_Pos.Sword_MaxY)
			return true;
	}
	else return false;
}

ColliderManager* ColliderManager::s_pInstance = 0;