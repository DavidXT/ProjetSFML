#pragma once
#include "Entity.h"
class Ball:public Entity
{
public:
	Ball(int);
	sf::Shape& getBall();
	void setBallPosition(sf::Vector2f);
	void moveBall(float,sf::Vector2f);
	void stopShoot();
	void reload();
	bool getShoot();
	bool getIsNotCollide();
	void StopCollide();
	void Collide();
	sf::Vector2f direction;

private:
	bool canShoot;
	bool isNotCollide;
};

