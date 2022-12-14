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

// 플레이어와 칼의 좌표값 설정
void ColliderManager::set_defaultData()
{
	// 플레이어의 좌표를 가져옴
	player_Pos.Player_minX = player->get_XPos();
	player_Pos.Player_maxX = player->get_XPos() + player->get_XWidth();

	player_Pos.Player_minY = player->get_YPos() - player->get_height();
	player_Pos.Player_maxY = player->get_YPos();

	// 몬스터의 좌표를 가져옴
	enemy_Pos.Sword_MinX = enemy->get_Xpos();
	enemy_Pos.Sword_MaxX = enemy->get_Xpos() + enemy->get_XWidth();

	enemy_Pos.Sword_MaxY = enemy->get_Ypos();
	enemy_Pos.Sword_MinY = enemy->get_Ypos() - enemy->get_height();
}

bool ColliderManager::AABB_Coll()
{
	// NULL이 아니면
	if (enemy != NULL) {

		// 캐릭터와 칼의 좌표값을 가져옴
		set_defaultData();

		// 플레이어와 칼의 x좌표값이 충돌하면
		if (player_Pos.Player_maxX >= enemy_Pos.Sword_MinX &&
			player_Pos.Player_minX <= enemy_Pos.Sword_MaxX) {

			// 플레이어와 칼의 y좌표값이 충돌하면
			if (player_Pos.Player_minY <= enemy_Pos.Sword_MaxY &&
				player_Pos.Player_maxY >= enemy_Pos.Sword_MinY) {

				// true를 반환함
				player->set_IsColl(true);
				return true;
			}
		}
		// 그외에는
		else {
			// false를 반환함
			player->set_IsColl(false);
			return false;
		}
	}
}

ColliderManager* ColliderManager::s_pInstance = 0;