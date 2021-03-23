#pragma once
#include <SFML/Graphics.hpp>
class Player
{
public:
	Player();
	void moveLeft(float);
	void moveRight(float);
	void moveUp(float);
	void moveDown(float);
	sf::CircleShape getPlayer();
private:
	sf::CircleShape p;
};

