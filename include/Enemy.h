#pragma once
#include <iostream>
#include "SDLGameObject.h"

class Enemy : public SDLGameObject {
public:
    Enemy(const LoaderParams* pParams);
    virtual void draw();
    virtual void drawFrame();
    /*virtual void drawChangeFrame();*/
    virtual void update();
    void fall();
    virtual void handleInput();
    virtual void clean();

    int get_Xpos();
    int get_XWidth();

    int get_Ypos();
    int get_height();

private:
    const int Width = 28;
    const int height = 48;

    int enemyY = 0;
    int fallSpeed = 2;
    float fastTime = 0;
};