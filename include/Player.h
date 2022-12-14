#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"


class Player : public SDLGameObject {
public:
    // Player의 부모 클래스인 GameObject에서 이미 virtual을 사용하여 다형성을 가짐.
    // 자식 클래스에서 재정의한 함수는 virtual을 생략해도 저절로 가상함수가 됨.
    // 하지만 자식 클래스에서도 virtual을 사용하는이 관례임. (코드 이해를 수월하게 하기 위해서)
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void drawFrame();
    /*virtual void drawChangeFrame();*/
    virtual void update();
    virtual void handleInput();
    virtual void clean();


    // 플레이어의 좌표를 받아오는 코드
    int get_XPos();
    int get_XWidth();

    int get_YPos();
    int get_height();

    // 플레이어가 충돌되었다는것을 알려줌
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
