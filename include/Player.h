#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
    void load(int x, int y, int width, int height, int moveSpeed, /*int currentRow, int currentFrame,*/ std::string textureID); // 함수호출 인수에 moveSpeed를 추가. 이동속도 변경을 가능하게 함.
    void draw(SDL_Renderer* pRenderer);
    void drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer); // 함수호출 인수에 currentRow와 currentFrame을 추가. 프레임변경을 가능하게 함.
    void update();
    void clean() {};

private:
    //bool PLeft = false;
};
