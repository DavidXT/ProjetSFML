#pragma once
#include "Brick.h"
#include "Ball.h"
#include "PlatForm.h"
class gameManager
{
public:
	gameManager(int);
	Brick* getBrick(int,int);
	Ball& getBall(int);
	sf::Text getScore();
	void setScore();
	PlatForm* GetPlatForm(int);
private:
	Ball* AllBall[Global::nbBall];
	std::vector<std::vector<Brick*>> AllBrick;
	std::vector<PlatForm*> Vec_Plat;
private:
	
};

