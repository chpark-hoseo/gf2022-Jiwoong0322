#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
    // Player�� �θ� Ŭ������ GameObject���� �̹� virtual�� ����Ͽ� �������� ����.
    // �ڽ� Ŭ�������� �������� �Լ��� virtual�� �����ص� ������ �����Լ��� ��.
    // ������ �ڽ� Ŭ���������� virtual�� ����ϴ��� ������. (�ڵ� ���ظ� �����ϰ� �ϱ� ���ؼ�)
    virtual void load(int x, int y, int width, int height, int moveSpeed, std::string textureID); // �Լ�ȣ�� �μ��� moveSpeed�� �߰�. �̵��ӵ� ������ �����ϰ� ��.
    virtual void draw(SDL_Renderer* pRenderer);
    virtual void drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer); // �Լ�ȣ�� �μ��� currentRow�� currentFrame�� �߰�. �����Ӻ����� �����ϰ� ��.
    virtual void update();
    virtual void clean() {};

private:
    //bool PLeft = false;
};
