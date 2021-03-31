#pragma once
#include <SFML/Graphics.hpp>
class Viseur
{
public : 
	Viseur(sf::RenderWindow&);
	void Project(sf::Vector2i, sf::Vector2f, sf::Vector2f);
	void draw(); 
	sf::Vertex line[4];

private:
	float pente; 
	float origin; 
	sf::RenderWindow& window; 


};

