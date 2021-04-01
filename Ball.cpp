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
	Global::_score -= 10;
	Global::dispoBall--;
}

void Ball::reload()
{
	canShoot = true;
	Global::dispoBall++;
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

/* Check if ball go out of screen */
void Ball::CheckScreen(float deltaTime,Player* p) {
	if (!getShoot()) {
		const sf::Vector2f& oPosition = getBall().getPosition();
		float fX = oPosition.x + (direction.x * (float)Global::bulletSpeed * deltaTime);
		float fY = oPosition.y + (direction.y * (float)Global::bulletSpeed * deltaTime);
		getBall().setPosition(fX, fY);
		if (getBall().getGlobalBounds().left < 0)
		{
			direction.x *= -1;
		}
		if (getBall().getGlobalBounds().left + getBall().getGlobalBounds().width > Global::ScreenX)
		{
			direction.x *= -1;
		}
		if (getBall().getGlobalBounds().top < 0)
		{
			direction.y *= -1;
		}
		if (getBall().getGlobalBounds().top + getBall().getGlobalBounds().height > Global::ScreenY)
		{
			setBallPosition(p->GetPlayerPosition());
			reload();
		}
	}
}
