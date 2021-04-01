#include "Ball.h"

/* Constructor */
Ball::Ball(int _radius)
{
	_shape = new sf::CircleShape(_radius);
	_shape->setOrigin(_radius * 0.5, _radius * 2);
	BoxCollision = _shape->getGlobalBounds();
	canShoot = true;
	isNotCollide = true;
}

/* Return shape of ball */
sf::Shape& Ball::getBall()
{
	return *_shape;
}
/* Change ball position */
void Ball::setBallPosition(sf::Vector2f cs)
{
	_shape->setPosition(cs);
}

/* Check for not shooting ball */
void Ball::stopShoot()
{
	canShoot = false;
	Global::_score -= 10;
	Global::dispoBall--;
}

/* Check for ball shoot */
void Ball::reload()
{
	canShoot = true;
	Global::dispoBall++;
}

/* Return state of ball */
bool Ball::getShoot()
{
	return canShoot;
}

/* Return state of ball */
bool Ball::getIsNotCollide()
{
	return isNotCollide;
}

/* Change collider state */
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
		sf::FloatRect BallRect = getBall().getGlobalBounds();
		const sf::Vector2f& oPosition = getBall().getPosition();
		float fX = oPosition.x + (direction.x * (float)Global::bulletSpeed * deltaTime);
		float fY = oPosition.y + (direction.y * (float)Global::bulletSpeed * deltaTime);
		getBall().setPosition(fX, fY);
		if (getBall().getGlobalBounds().left < 0 && isNotCollide)
		{
			Collide();
			direction.x *= -1;
		}
		if (getBall().getGlobalBounds().left + getBall().getGlobalBounds().width > Global::ScreenX && isNotCollide)
		{
			Collide();
			direction.x *= -1;
		}
		if (getBall().getGlobalBounds().top < 0 && isNotCollide)
		{
			Collide();
			direction.y *= -1;
		}
		if (getBall().getGlobalBounds().top + getBall().getGlobalBounds().height > Global::ScreenY)
		{
			setBallPosition(p->GetPlayerPosition());
			reload();
		}
	}
}
