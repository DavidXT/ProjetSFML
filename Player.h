#pragma once
#include <SFML/Graphics.hpp>
#include "gameManager.h"
class Player
{
public:
	Player();
	void moveLeft(float);
	void moveRight(float);
	void moveUp(float);
	void moveDown(float);
	sf::Vector2f GetPlayerPosition(); 
	sf::RectangleShape& getPlayer();
	float angle;
	 
private:
	sf::RectangleShape p;
	sf::FloatRect BoxCollision; 
	sf::Vector2f Size;
};

