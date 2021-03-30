#include "Player.h"
#include "Ball.h"

Ball::Ball(int _radius)
{
	_shape = new sf::CircleShape(_radius);
	_shape->setOrigin(_radius * 0.5, _radius * 2);
	BoxCollision = _shape->getGlobalBounds();
	canShoot = true;
	isNotCollide = true;
}

sf::Shape& Ball::getBall()
{
	return *_shape;
}

void Ball::setBallPosition(sf::Vector2f cs)
{
	_shape->setPosition(cs);
}

void Ball::moveBall(float deltaTime,sf::Vector2f target) {
	_shape->move(0.0f, -Global::bulletSpeed*deltaTime);
}

void Ball::stopShoot()
{
	canShoot = false;
}

void Ball::reload()
{
	canShoot = true;
}

bool Ball::getShoot()
{
	return canShoot;
}

bool Ball::getIsNotCollide()
{
	return isNotCollide;
}

void Ball::StopCollide()
{
	isNotCollide = true;
}

void Ball::Collide()
{
	isNotCollide = false;
}
