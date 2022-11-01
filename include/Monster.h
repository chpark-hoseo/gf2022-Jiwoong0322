#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
public:
    void load(int x, int y, int width, int height, int moveSpeed, std::string textureID); // �Լ�ȣ�� �μ��� moveSpeed�� �߰�. �̵��ӵ� ������ �����ϰ� ��.
    void draw(SDL_Renderer* pRenderer);
    void drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer); // �Լ�ȣ�� �μ��� currentRow�� currentFrame�� �߰�. �����Ӻ����� �����ϰ� ��.
    void update();
    void clean() {};

private:
    //bool MLeft = false;
};