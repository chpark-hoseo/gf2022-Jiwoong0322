#include <iostream>
#include "Game.h"
#include "Objects.h"

Objects::Objects(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Objects::draw()
{
	SDLGameObject::draw();
}

void Objects::update()
{
	SDLGameObject::update();
}

void Objects::handleInput() {}

void Objects::clean() {}