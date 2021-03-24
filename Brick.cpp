#include <SFML/Graphics.hpp>
#include "Global.h"
#include "Brick.h"

Brick::Brick(int x, int y)
{
	brick.setSize(sf::Vector2f(50, 80));
	brick.setPosition(y,x);
	brick.setOrigin(0, 0);
	brick.setSize(sf::Vector2f(Global::sizeXBrick,Global::sizeYBrick));
}

sf::RectangleShape& Brick::getBrick()
{
	return brick;
}
