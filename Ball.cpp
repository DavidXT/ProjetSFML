#include "Player.h"
#include "Global.h"
#include "Ball.h"

sf::CircleShape b;

Ball::Ball()
{
	b.setRadius(10);
	b.setOrigin(b.getRadius() * 0.5, b.getRadius() * 2);
	b.setPosition(Global::ScreenX / 2, Global::ScreenY);
}

sf::CircleShape Ball::getBall()
{
	return b;
}

void Ball::setBallPosition(sf::CircleShape cs)
{
	b.setPosition(cs.getPosition());
}

void Ball::moveBall(float deltaTime,sf::Vector2f target) {
	b.move(0.0f, -Global::bulletSpeed*deltaTime);
}