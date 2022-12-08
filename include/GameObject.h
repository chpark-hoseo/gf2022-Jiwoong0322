#pragma once
#include <main.h>
#include <iostream>
#include "LoaderParams.h"
#include "TextureManager.h"

class GameObject {
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
    virtual ~GameObject() {}

protected:
    GameObject(const LoaderParams* pParams) {}
};