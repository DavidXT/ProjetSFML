#include <vector>
#include "Global.h"
#include "gameManager.h"

gameManager::gameManager(int nbLine)
{
	for (int i = 0; i < nbLine; i++) {
		std::vector<Brick*> Line;
		for (int j = 0; j < Global::nbBrick; j++) {
			Line.push_back(nullptr);
		}
		AllBrick.push_back(Line);
	}
	for (int i = 0; i < nbLine; i++) {
		for (int j = 0; j < Global::nbBrick; j++) {
			AllBrick[i][j] = new Brick(Global::sizeYBrick * i, Global::sizeXBrick * j, rand() % 3 + 1);
		}
	}

	for (int i = 0; i < Global::nbBall; i++) {
		AllBall[i] = new Ball(Global::ballSize);
	}
}

Brick* gameManager::getBrick(int x, int y)
{
	return AllBrick[x][y];
}

Ball& gameManager::getBall(int i)
{
	return *AllBall[i];
}