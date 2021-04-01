#pragma once
#include "Brick.h"
#include "Ball.h"
#include "PlatForm.h"
class gameManager
{
public: 
	gameManager(int); //Constructor
	Brick* getBrick(int,int); //Return brick at index i,j
	Ball& getBall(int); // Return ball at index i
	PlatForm* GetPlatForm(int); //Return platform at index i
	int GetAllBricks();  //Return all brick
	bool checkWin(); //Return state of game
	std::vector<std::vector<Brick*>> AllBrick; // Table of all brick
private:
	Ball* AllBall[Global::nbBall]; // Table of all ball
	std::vector<PlatForm*> Vec_Plat; //Table of all platform
private:
	
};

