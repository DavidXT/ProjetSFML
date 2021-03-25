#include "Player.h"
#include "Global.h"

Player::Player() {
	p.setSize(sf::Vector2f(80, 50)); 
	p.setOrigin(p.getSize().x * 0.5, p.getSize().y * 0.5);
	p.setPosition(Global::ScreenX / 2, Global::ScreenY - p.getSize().y);
	BoxCollision = p.getGlobalBounds(); 
}


void Player::moveDown(float deltaTime) {
	p.move(0.0f, Global::playerSpeed * deltaTime);
}

sf::RectangleShape& Player::getPlayer() {
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

sf::Vector2f Player::GetPlayerPosition() 
{
	return p.getPosition(); 
}