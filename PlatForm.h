#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
class PlatForm
{
public :
	PlatForm(float);
	sf::RectangleShape& GetPlateform();
	void Collide(Ball*, bool, sf::Vector2f); 
private:
	sf::RectangleShape f;
	sf::FloatRect BoxCollision;
	sf::Vector2f Size; 
	float CoeffPos; 


};

