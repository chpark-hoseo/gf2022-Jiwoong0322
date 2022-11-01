#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
    void load(int x, int y, int width, int height, int moveSpeed, /*int currentRow, int currentFrame,*/ std::string textureID); // �Լ�ȣ�� �μ��� moveSpeed�� �߰�. �̵��ӵ� ������ �����ϰ� ��.
    void draw(SDL_Renderer* pRenderer);
    void drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer); // �Լ�ȣ�� �μ��� currentRow�� currentFrame�� �߰�. �����Ӻ����� �����ϰ� ��.
    void update();
    void clean() {};

private:
    //bool PLeft = false;
};
