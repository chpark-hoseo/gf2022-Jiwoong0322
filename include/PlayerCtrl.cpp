#include "PlayerCtrl.h"
#include <SDL2/SDL_image.h>
#include <main.h>

//PlayerCtrl* PlayerCtrl::g_pInstance = 0;
//
//bool PlayerCtrl::moving()
//{
//	SDL_Event event;
//
//	while (SDL_PollEvent(&event))
//	{
//		switch (event.type)
//		{
//		case SDL_KEYDOWN:
//			switch (event.key.keysym.sym)
//			{
//			case SDLK_LEFT: // ����Ű
//				x--;
//				break;
//			case SDLK_RIGHT: // ������Ű
//				x++;
//				break;
//			case SDLK_UP: // ����Ű
//				y--;
//				break;
//			case SDLK_DOWN: // �Ʒ���Ű
//				y++;
//				break;
//			}
//			break;
//		}
//
//		return false;
//	}
//
//
//	return  false;
//}