#pragma once
#include <iostream>
#include "SDLGameObject.h"


class Player : public SDLGameObject {
public:
    // Player�� �θ� Ŭ������ GameObject���� �̹� virtual�� ����Ͽ� �������� ����.
    // �ڽ� Ŭ�������� �������� �Լ��� virtual�� �����ص� ������ �����Լ��� ��.
    // ������ �ڽ� Ŭ���������� virtual�� ����ϴ��� ������. (�ڵ� ���ظ� �����ϰ� �ϱ� ���ؼ�)
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void drawFrame();
    /*virtual void drawChangeFrame();*/
    virtual void update();
    virtual void handleInput();
    virtual void clean();

    Vector2D* p_Box;

private:
    //bool PLeft = false;
};
