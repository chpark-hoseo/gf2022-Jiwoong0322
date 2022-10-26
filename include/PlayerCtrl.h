#pragma once
#include <iostream>
#include <main.h>
#include <map>

class PlayerCtrl
{
public:

	static PlayerCtrl* Instance()
	{
		if (g_pInstance == 0)
		{
			g_pInstance = new PlayerCtrl();
		}

		return g_pInstance;
	}

	int PlayerX = 0;
	int PlayerY = 0;
	bool moving();


private:
	//std::map<std::string, SDL_Texture*> m_PlayerCtrlMap;

	PlayerCtrl() {}
	~PlayerCtrl() {}

	static PlayerCtrl* g_pInstance;
};