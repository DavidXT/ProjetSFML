#include "Entity.h"
#include "Brick.h"

Brick::Brick(int x, int y, int hp)
{
	_shape = new sf::RectangleShape(sf::Vector2f(Global::sizeXBrick, Global::sizeYBrick));
	_shape->setPosition(y,x);
	_shape->setOrigin(0, 0);
	_shape->setOutlineColor(sf::Color::Black);
	_shape->setOutlineThickness(-1);
	isDestroyed = false;
	lifePoint = hp;
	switch (lifePoint)
	{
	case 0:
		isDestroyed = true;
		break;
	case 1:
		_shape->setFillColor(sf::Color::Green);
		break;
	case 2:
		_shape->setFillColor(sf::Color::Blue);
		break;
	case 3:
		_shape->setFillColor(sf::Color::Red);
		break;
	}
}

sf::Shape& Brick::getBrick()
{
	return *_shape;
}

void Brick::getDamage() {
	lifePoint--;
	switch (lifePoint) 
	{
		case 0 :
			isDestroyed = true;
			break; 
		case 1 : 
			_shape->setFillColor(sf::Color::Green);
			break; 
		case 2 :
			_shape->setFillColor(sf::Color::Blue);
			break; 
		case 3 : 
			_shape->setFillColor(sf::Color::Red);
			break; 
	}
		
}

bool& Brick::getDestroyed() {
	return isDestroyed;
}
