#pragma once
#include <iostream>
#include "SDLGameObject.h"

class Enemy : public SDLGameObject {
public:
    Enemy(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void handleInput();
    virtual void clean();

private:

};