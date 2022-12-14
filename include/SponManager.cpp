#include "SponManager.h"
#include "ColliderManager.h"
#include "LoaderParams.h"

#include "Game.h"

// ���ʹ��� ��ü������ �޾ƿ�
void SponManager::setEnemyData(Enemy* enemy)
{
	this->m_enemy = enemy;
}

// ���� ������ Į�� X��ǥ�� �޾ƿ�
void SponManager::ResponXPos(int xPos)
{
	this->respon_XPos = xPos;
}

// Į�� ���� ����
Enemy* SponManager::Respon()
{
	// Null�� �ƴϸ�
	if (m_enemy != NULL) {

		// Į�� �ٴڰ� �浹�ϴ��� �˻�
		if (m_enemy->get_Ypos() >= TheGame::Instance()->GroundYPos)
		{
			m_enemy = NULL; // �浹�ϸ� m_enemy�� NULL�� ��
		}

		//printf("�۵�");
	}
	// NULL�̸�
	else {
		// ���ο� Į ��ü�� ����
		Enemy* enemy = new Enemy(new LoaderParams(respon_XPos, -40, 28, 48, "Knife"));
		TheColliderMng::Instance()->set_Enemy(enemy); // Collidermanager�� setEnemy�� ���� ������ ��ü�� �Է���
		return enemy; // Į�� ��ȯ
	}

	return NULL;
}

SponManager* SponManager::s_pInstance = 0;