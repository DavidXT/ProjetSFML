#pragma once
#include "Entity.h"
class Brick:public Entity
{
public: 
	Brick(int,int, int);
	sf::Shape& getBrick();
	bool& getDestroyed();
	void getDamage();
private:
	sf::Vector2f Size;
	bool isDestroyed;
	int lifePoint;
};

