#include "Player.h"
#include "Global.h"

sf::CircleShape p;

Player::Player() {
	p.setRadius(20);
	p.setOrigin(p.getRadius() * 0.5, p.getRadius() * 2);
	p.setPosition(Global::ScreenX / 2, Global::ScreenY);
}


void Player::moveDown(float deltaTime) {
	p.move(0.0f, Global::playerSpeed * deltaTime);
}

sf::CircleShape Player::getPlayer() {
	return p;
}
void Player::moveUp(float deltaTime) {
	p.move(0.0f, -Global::playerSpeed * deltaTime);
}

void Player::moveRight(float deltaTime) {
	p.move(Global::playerSpeed * deltaTime, 0.0f);
}

void Player::moveLeft(float deltaTime)
{
	p.move(-Global::playerSpeed * deltaTime, 0.0f);
}