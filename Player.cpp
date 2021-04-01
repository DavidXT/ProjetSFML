#include "Player.h"
 /* Constructor */
Player::Player(sf::Vector2f _size) {
	_shape = new sf::RectangleShape(_size);
	_shape->setOrigin(_size.x * 0.5, _size.y * 0.5);
	_shape->setPosition(Global::ScreenX / 2, Global::ScreenY);
	BoxCollision = _shape->getGlobalBounds();
	_shape->setFillColor(sf::Color(255, 106, 3, 255));
}

/* Return shape of player */
sf::Shape& Player::getPlayer() {
	return *_shape;
}
 /* Return player position */
sf::Vector2f Player::GetPlayerPosition() 
{
	return _shape->getPosition(); 
}