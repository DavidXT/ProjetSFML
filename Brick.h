#pragma once

class Brick
{
public: 
	Brick(int,int);
	sf::RectangleShape& getBrick();
private:
	sf::RectangleShape brick;
	sf::FloatRect BoxCollision;
	sf::Vector2f Size;
};

