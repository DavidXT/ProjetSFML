#include "Viseur.h"
#include "Global.h"
#include <iostream>

Viseur::Viseur(sf::RenderWindow& renderWindow) : window(renderWindow)
{
	
}
void Viseur::Project(sf::Vector2i MousePosition, sf::Vector2f PlayerPosition, sf::Vector2f directionSecondRay )
{
	float RayLength = 200; 
	sf::Vector2f oMouse = (sf::Vector2f)MousePosition; 
	pente = (PlayerPosition.y - oMouse.y)/ (PlayerPosition.x - oMouse.x); 
	origin = oMouse.y - pente * oMouse.x;
	line[0] = PlayerPosition;  
	float XLeft = 0; 
	float XRight = Global::ScreenX;
	float YTop = 0; 
	float YLeft = pente * XLeft + origin; 
	float YRight = pente * XRight + origin;
	float XTop = ( YTop - origin )/ pente;
	if (XTop > XLeft && XTop < XRight) 
	{
		line[1].position.x = XTop; 
		line[1].position.y = YTop; 
		line[2].position = line[1].position;
		float pente2 = -pente; 
		float origin2 = -MousePosition.y - pente2 * MousePosition.x; ;
		line[3].position.x = line[2].position.x + RayLength * directionSecondRay.x;
		line[3].position.y = line[2].position.y + RayLength * directionSecondRay.y * (-1); 
	}
	else if (YLeft > YTop && YLeft < YRight) 
	{
		line[1].position.x = XLeft; 
		line[1].position.y = YLeft;
		line[2].position = line[1].position; 
		line[3].position.x = line[2].position.x + RayLength * directionSecondRay.x * (-1);
		line[3].position.y = line[2].position.y + RayLength * directionSecondRay.y;
	}
	else if (YRight < YLeft && YRight > YTop)
	{
		line[1].position.x = XRight;
		line[1].position.y = YRight;
		line[2].position = line[1].position;
		line[3].position.x = line[2].position.x + RayLength * directionSecondRay.x * (-1);
		line[3].position.y = line[2].position.y + RayLength * directionSecondRay.y ;
	}
	
}
void Viseur::draw() {

	line[0].color = sf::Color::White; 
	line[1].color = sf::Color::White; 
	line[2].color = sf::Color::White; 
	line[3].color = sf::Color::White; 
	window.draw(line, 4, sf::Lines); 
}

