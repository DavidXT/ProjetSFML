#pragma once
#include "Brick.h"
#include "PlatForm.h"
class gameManager
{
public:
	gameManager(int);
	Brick* getBrick(int,int);
	PlatForm* GetPlatForm(int);
	std::vector<std::vector<Brick*>> AllBrick;
	std::vector<PlatForm*> Vec_Plat;
private:
	
};

