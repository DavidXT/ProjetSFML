#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "Ball.h"
class PlatForm
{
public:
	PlatForm(float);
	sf::RectangleShape& GetPlateform();
	void Collide(Ball&, sf::Sound&); 
private:
	sf::RectangleShape f;
	sf::FloatRect BoxCollision;
	sf::Vector2f Size;
	float CoeffPos;


};

