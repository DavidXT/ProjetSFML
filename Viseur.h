#pragma once
#include <SFML/Graphics.hpp>
#include "gameManager.h"
#include "Brick.h"
class Viseur
{
public : 
	Viseur(sf::RenderWindow&);
	void Project(sf::Vector2i, sf::Vector2f, sf::Vector2f, gameManager*);
	void draw(); 
	sf::Vertex line[4];
	sf::FloatRect boxCollision; 

private:
	float pente; 
	float origin; 
	sf::RenderWindow& window; 
 

};

