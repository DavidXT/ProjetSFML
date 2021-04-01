#pragma once
#include "Entity.h"
#include "Ball.h"
class Brick:public Entity
{
public: 
	Brick(int,int, int); //Brick constructor
	sf::Shape& getBrick(); //Get Shape of brick
	bool& getDestroyed(); //Check if brick is destroyed
	void setDestroyed(); //Change state of brick
	void resetDestroyed(); //Change state of brick
	void getDamage(); //Damage brick
	void CheckColor(); //Change color of brick
	void CheckCollision(Ball& b); //Check collision with ball
private:
	sf::Vector2f Size; //Size of brick
	bool isDestroyed; //Is Destroyed boolean
	int lifePoint; //Life point of brick
};

