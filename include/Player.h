#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"


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


    // �÷��̾��� ��ǥ�� �޾ƿ��� �ڵ�
    int get_XPos();
    int get_XWidth();

    int get_YPos();
    int get_height();

    // �÷��̾ �浹�Ǿ��ٴ°��� �˷���
    void set_IsColl(bool IsColl);

    Vector2D* p_Box;

private:
    bool IsColl;
    int Hp = 3;

    const int width = 32;
    const int height = 32;

    const int delayTime = 60;
    int delayCnt = 0;
    //bool PLeft = false;
};
