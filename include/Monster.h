#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
public:
    // Monster�� �θ� Ŭ������ GameObject���� �̹� virtual�� ����Ͽ� �������� ����.
    // �ڽ� Ŭ�������� �������� �Լ��� virtual�� �����ص� ������ �����Լ��� ��.
    // ������ �ڽ� Ŭ���������� virtual�� ����ϴ��� ������. (�ڵ� ���ظ� �����ϰ� �ϱ� ���ؼ�)
    virtual void load(int x, int y, int width, int height, int moveSpeed, std::string textureID);
    virtual void draw(SDL_Renderer* pRenderer);
    virtual void drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer);
    virtual void update();
    virtual void clean() {};

private:
    //bool MLeft = false;
};