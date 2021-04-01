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
	int GetAllBricks(); 
	std::vector<std::vector<Brick*>> AllBrick;
private:
	Ball* AllBall[Global::nbBall];
	std::vector<PlatForm*> Vec_Plat;
private:
	
};

