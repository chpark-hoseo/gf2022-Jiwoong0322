#include "ColliderManager.h"

void ColliderManager::set_PlayerObj(Player* player)
{
	this->player = player;

	/*player_Pos.Player_minX = player->get_XPos();
	player_Pos.Player_maxX = player->get_XPos() + player->get_XWidth();

	player_Pos.Player_minY = player->get_YPos() - player->get_YWidth();*/
}

void ColliderManager::set_Enemy(Enemy* enemy)
{
	this->enemy = enemy;

	/*enemy_Pos.Sword_MinX = enemy->get_Xpos();
	enemy_Pos.Sword_MaxX = enemy->get_Xpos() + enemy->get_XWidth();

	enemy_Pos.Sword_MaxY = enemy->get_Ypos();*/

	//printf("%d", enemy_Pos.Sword_MaxX);
}

void ColliderManager::set_defaultData()
{
	// ÇÃ·¹ÀÌ¾îÀÇ ÁÂÇ¥¸¦ °¡Á®¿È
	player_Pos.Player_minX = player->get_XPos();
	player_Pos.Player_maxX = player->get_XPos() + player->get_XWidth();

	player_Pos.Player_minY = player->get_YPos() - player->get_height();
	player_Pos.Player_maxY = player->get_YPos();

	// ¸ó½ºÅÍÀÇ ÁÂÇ¥¸¦ °¡Á®¿È
	enemy_Pos.Sword_MinX = enemy->get_Xpos();
	enemy_Pos.Sword_MaxX = enemy->get_Xpos() + enemy->get_XWidth();

	enemy_Pos.Sword_MaxY = enemy->get_Ypos();
	enemy_Pos.Sword_MinY = enemy->get_Ypos() - enemy->get_height();
}

bool ColliderManager::AABB_Coll()
{
	if (enemy != NULL) {

		set_defaultData();

		if (player_Pos.Player_maxX >= enemy_Pos.Sword_MinX &&
			player_Pos.Player_minX <= enemy_Pos.Sword_MaxX) {

			if (player_Pos.Player_minY <= enemy_Pos.Sword_MaxY &&
				player_Pos.Player_maxY >= enemy_Pos.Sword_MinY) {

				player->set_IsColl(true);
				return true;
			}
		}
		else {
			player->set_IsColl(false);
			return false;
		}
	}
}

ColliderManager* ColliderManager::s_pInstance = 0;