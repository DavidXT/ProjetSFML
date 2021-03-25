#pragma once
#include <SFML/Graphics.hpp>
class PlatForm
{
public :
	PlatForm(float);
private:
	sf::RectangleShape f;
	sf::FloatRect BoxCollision;
	sf::Vector2f Size; 
	float CoeffPos; 

};

