#include "Player.h"
#include "Global.h"
#include "Ball.h"

sf::CircleShape b;

Ball::Ball()
{
	b.setRadius(10);
	b.setOrigin(b.getRadius() * 0.5, b.getRadius() * 2);
	//b.setPosition(Global::ScreenX / 2, Global::ScreenY/2);
}

sf::CircleShape Ball::getBall()
{
	return b;
}

void Ball::setBallPosition(sf::Vector2f cs)
{
	b.setPosition(cs);
}

void Ball::moveBall(float deltaTime,sf::Vector2f target) {
	b.move(0.0f, -Global::bulletSpeed*deltaTime);
}