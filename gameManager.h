#pragma once
#include "Brick.h"

class gameManager
{
public:
	gameManager(int);
	Brick* getBrick(int,int);
	std::vector<std::vector<Brick*>> AllBrick;
private:
};

