#include "Player.h"

Player::Player(sf::Vector2f _size) {
	_shape = new sf::RectangleShape(_size);
	_shape->setOrigin(_size.x * 0.5, _size.y * 0.5);
	_shape->setPosition(Global::ScreenX / 2, Global::ScreenY);
	BoxCollision = _shape->getGlobalBounds();
	_shape->setFillColor(sf::Color(255, 106, 3, 255));
}


void Player::moveDown(float deltaTime) {
	_shape->move(0.0f, Global::playerSpeed * deltaTime);
}

sf::Shape& Player::getPlayer() {
	return *_shape;
}
void Player::moveUp(float deltaTime) {
	_shape->move(0.0f, -Global::playerSpeed * deltaTime);
}

void Player::moveRight(float deltaTime) {
	_shape->move(Global::playerSpeed * deltaTime, 0.0f);
}

void Player::moveLeft(float deltaTime)
{
	_shape->move(-Global::playerSpeed * deltaTime, 0.0f);
}

sf::Vector2f Player::GetPlayerPosition() 
{
	return _shape->getPosition(); 
}