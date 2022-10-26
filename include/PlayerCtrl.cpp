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
//			case SDLK_LEFT: // 왼쪽키
//				x--;
//				break;
//			case SDLK_RIGHT: // 오른쪽키
//				x++;
//				break;
//			case SDLK_UP: // 위쪽키
//				y--;
//				break;
//			case SDLK_DOWN: // 아래쪽키
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