#pragma once
#include "Entity.h"
class Player:public Entity
{
public:
	Player(sf::Vector2f); 
	sf::Vector2f GetPlayerPosition(); 
	sf::Shape& getPlayer();	 
private:
	sf::Vector2f Size;
};

