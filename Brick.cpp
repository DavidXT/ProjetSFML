#include "Brick.h"

/* Constructor */
Brick::Brick(int x, int y, int hp)
{
	_shape = new sf::RectangleShape(sf::Vector2f(Global::sizeXBrick, Global::sizeYBrick));
	_shape->setPosition(y,x);
	_shape->setOrigin(0, 0);
	_shape->setOutlineColor(sf::Color::Black);
	_shape->setOutlineThickness(-1);
	isDestroyed = false;
	lifePoint = hp;
	CheckColor();
}

/* Return shape of brick */
sf::Shape& Brick::getBrick()
{
	return *_shape;
}

/* Damage brick */
void Brick::getDamage() {
	lifePoint--;
	CheckColor();
}

/* Change color of brick*/
void Brick::CheckColor() {
	switch (lifePoint)
	{
	case 0:
		isDestroyed = true;
		Global::_score += 1;
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

/* Brick is destroyed */
bool& Brick::getDestroyed() {
	return isDestroyed;
}

void Brick::CheckCollision(Ball& b) {
	sf::Shape& tmpRect = getBrick();
	if (b.getBall().getGlobalBounds().intersects(tmpRect.getGlobalBounds()) && b.getIsNotCollide()) {
		float b_collision = tmpRect.getGlobalBounds().top + tmpRect.getGlobalBounds().height - b.getBall().getGlobalBounds().top; //Bottom 
		float t_collision = b.getBall().getGlobalBounds().top + b.getBall().getGlobalBounds().height - tmpRect.getGlobalBounds().top; //Top
		float l_collision = b.getBall().getGlobalBounds().left + b.getBall().getGlobalBounds().width - tmpRect.getGlobalBounds().left; //Left
		float r_collision = tmpRect.getGlobalBounds().left + tmpRect.getGlobalBounds().width - b.getBall().getGlobalBounds().left; //Right
		if (t_collision <= b_collision && t_collision <= l_collision && t_collision <= r_collision || b_collision <= t_collision && b_collision <= l_collision && b_collision <= r_collision)
		{
			if (l_collision <= r_collision && l_collision <= t_collision && l_collision <= b_collision || r_collision <= l_collision && r_collision <= t_collision && r_collision <= b_collision)
			{
				b.direction.x *= -1;
			}
			b.direction.y *= -1;
		}
		if (l_collision <= r_collision && l_collision <= t_collision && l_collision <= b_collision || r_collision <= l_collision && r_collision <= t_collision && r_collision <= b_collision)
		{
			b.direction.x *= -1;
		}
		b.Collide();
		getDamage();
	}
	else {
		b.StopCollide();
	}
}