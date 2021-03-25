#pragma once

class Brick
{
public: 
	Brick(int,int);
	sf::RectangleShape& getBrick();
	bool& getDestroyed();
	void getDamage();
private:
	sf::RectangleShape brick;
	sf::FloatRect BoxCollision;
	sf::Vector2f Size;
	bool isDestroyed;
	int lifePoint;
};

