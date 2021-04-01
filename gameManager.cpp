#include <vector>
#include "Global.h"
#include "gameManager.h"

gameManager::gameManager(int nbLine)
{
	std::string ligne[Global::BrickLineCount][Global::BrickColumnCount] = 
		{ "X","O" ,"O","O","X","X","X","X",
		"X","O" ,"O","O","X","O","O","X",
		"X","X" ,"O","X","X","O","X","X",
		"X","O" ,"X","O","X","X","O","O",
		"X","O" ,"O","O","X","X","X","X"};
	for (int i = 0; i < nbLine; i++) {
		std::vector<Brick*> Line;
		for (int j = 0; j < Global::BrickColumnCount; j++) {
			Line.push_back(nullptr);
		}
		AllBrick.push_back(Line);
	}
	for (int i = 0; i < nbLine; i++) {
		for (int j = 0; j < Global::BrickColumnCount; j++) {
			AllBrick[i][j] = new Brick(Global::sizeYBrick * i, Global::sizeXBrick * j, rand() % 3 + 1);
		}
	}
	int k = 0;
	for (int i = 0; i < nbLine; i++) {
		for (int j = 0; j < Global::BrickColumnCount; j++) {
				if (ligne[i][j] == "O") {
					AllBrick[i][j]->resetDestroyed();
				}
				else {
					AllBrick[i][j]->setDestroyed();
				}
		}
	}

	for (int i = 0; i < Global::nbBall; i++) {
		AllBall[i] = new Ball(Global::ballSize);
	}
	Vec_Plat.push_back(new PlatForm(1)); 
	Vec_Plat.push_back(new PlatForm(3));
}

Brick* gameManager::getBrick(int x, int y)
{
	return AllBrick[x][y];
}

Ball& gameManager::getBall(int i)
{
	return *AllBall[i];
}
int gameManager::GetAllBricks() 
{
	return AllBrick.size(); 
}
PlatForm* gameManager::GetPlatForm(int i )
{
	return Vec_Plat[i]; 
}

