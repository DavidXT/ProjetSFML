#include <vector>
#include "Global.h"
#include "gameManager.h"

/* Constructor */
gameManager::gameManager(int nbLine)
{
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
			if (Global::map[i][j] == "O") {
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

/* Return brick at index x y */
Brick* gameManager::getBrick(int x, int y)
{
	return AllBrick[x][y];
}

/* Return ball at index i */
Ball& gameManager::getBall(int i)
{
	return *AllBall[i];
}

/* Return all brick */
int gameManager::GetAllBricks() 
{
	return AllBrick.size(); 
}

/* Return state of the game */
bool gameManager::checkWin()
{
	for (int i = 0; i < Global::BrickLineCount; i++) {
		for (int j = 0; j < Global::BrickColumnCount; j++) {
			if (!AllBrick[i][j]->getDestroyed()) {
				return false;
			}
		}
	}
	return true;
}

/* Return platform at index i */
PlatForm* gameManager::GetPlatForm(int i )
{
	return Vec_Plat[i]; 
}

