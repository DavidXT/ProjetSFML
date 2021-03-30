#pragma once
#include "Brick.h"
#include "Ball.h"
class gameManager
{
public:
	gameManager(int);
	Brick* getBrick(int,int);
	Ball& getBall(int);
private:
	Ball* AllBall[Global::nbBall];
	std::vector<std::vector<Brick*>> AllBrick;
};

