#include "Brick.h"

/* Constructor */
Brick::Brick(int x, int y, int hp)
{
	_shape = new sf::RectangleShape(sf::Vector2f(Global::sizeXBrick, Global::sizeYBrick));
	_shape->setPosition(y,x);
	_shape->setOrigin(0, 0);
	_shape->setOutlineColor(sf::Color::Black);
	_shape->setOutlineThickness(-1);
	isDestroyed = true;
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
		Global::_score += 15;
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

/* Change state of brick */
void Brick::setDestroyed() {
	isDestroyed = true;
}
/* Change state of brick */
void Brick::resetDestroyed()
{
	isDestroyed = false;
}

/* Check collision with ball */
void Brick::CheckCollision(Ball& b, sf::Sound& hit) {
	sf::FloatRect tmpRect = getBrick().getGlobalBounds();
	sf::FloatRect BallRect = b.getBall().getGlobalBounds();
	if (BallRect.intersects(tmpRect) && b.getIsNotCollide()) {
		b.Collide();
		float b_collision = tmpRect.top + tmpRect.height - BallRect.top; //Bottom 
		float t_collision = BallRect.top + BallRect.height - tmpRect.top; //Top
		float l_collision = BallRect.left + BallRect.width - tmpRect.left; //Left
		float r_collision = tmpRect.left + tmpRect.width - BallRect.left; //Right
		if ((t_collision <= b_collision && t_collision <= l_collision && t_collision <= r_collision) || (b_collision <= t_collision && b_collision <= l_collision && b_collision <= r_collision))
		{
			b.direction.y *= -1;
		}
		if ((l_collision <= r_collision && l_collision <= t_collision && l_collision <= b_collision) || (r_collision <= l_collision && r_collision <= t_collision && r_collision <= b_collision))
		{
			b.direction.x *= -1;
		}
		hit.play(); 
		getDamage();
	}
		b.StopCollide();
}