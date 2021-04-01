#pragma once
#include "Entity.h"
#include "Ball.h"
class Brick:public Entity
{
public: 
	Brick(int,int, int); //Brick constructor
	sf::Shape& getBrick(); //Get Shape of brick
	bool& getDestroyed(); //Check if brick is destroyed
	void setDestroyed();
	void resetDestroyed();
	void getDamage(); //Damage brick
	void CheckColor();
	void CheckCollision(Ball& b);
private:
	sf::Vector2f Size; //Size of brick
	bool isDestroyed; //Is Destroyed boolean
	int lifePoint; //Life point of brick
};

