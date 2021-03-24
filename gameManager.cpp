#include <vector>
#include <SFML/Graphics.hpp>
#include "Global.h"
#include "gameManager.h"



gameManager::gameManager(int nbLine)
{
	int sizeY = Global::ScreenY;
	int nbBrick = sizeY/100;
	for (int i = 0; i < nbLine; i++) {
		std::vector<Brick*> Line;
		for (int j = 0; j < nbBrick; j++) {
			Line.push_back(nullptr);
		}
		AllBrick.push_back(Line);
	}
	for (int i = 0; i < nbLine; i++) {
		for (int j = 0; j < nbBrick; j++) {
			AllBrick[i][j] = new Brick(10 + Global::sizeYBrick * i + 20 * i, 10 + Global::sizeXBrick * j + j * 20);
		}
	}
}

Brick* gameManager::getBrick(int x, int y)
{
	return AllBrick[x][y];
}
