#pragma once
#include "Entity.h"
#include "Player.h"
class Ball:public Entity
{
public:
	Ball(int); //Constructor Ball
	sf::Shape& getBall(); //Get Ball Shape
	void setBallPosition(sf::Vector2f); //Set Ball Position
	void moveBall(float,sf::Vector2f); //Move Ball Position
	void stopShoot(); //Can't shoot ball
	void reload(); //Can shoot ball
	bool getShoot(); //Get if can shoot 
	bool getIsNotCollide(); //Check ball collision
	void StopCollide(); //Change ball collision
	void Collide(); //Change ball collision
	void CheckScreen(float,Player*);
	sf::Vector2f direction; //Vector direction of ball

private:
	bool canShoot; //Bool can shoot
 	bool isNotCollide; //Bool check collision
};

