#include <SFML/Graphics.hpp>
#include "Global.h"
#include "Brick.h"

Brick::Brick(int x, int y, int hp)
{
	brick.setSize(sf::Vector2f(50, 80));
	brick.setPosition(y,x);
	brick.setOrigin(0, 0);
	brick.setSize(sf::Vector2f(Global::sizeXBrick,Global::sizeYBrick));
	isDestroyed = false;
	lifePoint = hp;
	switch (lifePoint)
	{
	case 0:
		isDestroyed = true;
		break;
	case 1:
		brick.setFillColor(sf::Color::Green);
		break;
	case 2:
		brick.setFillColor(sf::Color::Blue);
		break;
	case 3:
		brick.setFillColor(sf::Color::Red);
		break;
	}
}

sf::RectangleShape& Brick::getBrick()
{
	return brick;
}

void Brick::getDamage() {
	lifePoint--;
	switch (lifePoint) 
	{
		case 0 :
			isDestroyed = true;
			break; 
		case 1 : 
			brick.setFillColor(sf::Color::Green);
			break; 
		case 2 :
			brick.setFillColor(sf::Color::Blue);
			break; 
		case 3 : 
			brick.setFillColor(sf::Color::Red);
			break; 
	}
		
}

bool& Brick::getDestroyed() {
	return isDestroyed;
}
