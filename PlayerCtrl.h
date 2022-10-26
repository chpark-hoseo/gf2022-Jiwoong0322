#pragma once
#include <iostream>
#include <main.h>

class PlayerCtrl
{
public:

	bool moving();


private:
	PlayerCtrl() {}
	~PlayerCtrl() {};

	bool g_Pmoving = false;
};