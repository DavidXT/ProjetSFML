#pragma once
#include "Entity.h"
class Player:public Entity
{
public:
	Player(sf::Vector2f);
	void moveLeft(float);
	void moveRight(float);
	void moveUp(float);
	void moveDown(float);
	sf::Vector2f GetPlayerPosition(); 
	sf::Shape& getPlayer();
private:
	sf::Vector2f Size;
};

