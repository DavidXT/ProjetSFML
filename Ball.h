#pragma once
#include <SFML/Graphics.hpp>
class Ball
{
public:
	Ball();
	sf::CircleShape getBall();
	void setBallPosition(sf::CircleShape);
	void moveBall(float,sf::Vector2f);
private:
	sf::CircleShape b;
};

