#pragma once
#include <iostream>
#include "SDLGameObject.h"


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

    Vector2D* p_Box;

private:
    //bool PLeft = false;
};
