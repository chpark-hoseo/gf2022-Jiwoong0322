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

private:
    int enemyY = 0;
    int fallSpeed = 4;
    float fastTime = 0;
};