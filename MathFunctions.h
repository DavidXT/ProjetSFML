#pragma once
class MathFunctions
{
public : 
	static sf::Vector2f Normalize(sf::Vector2f); 
	static float Norme(sf::Vector2f); 
	static sf::Vector2f ResultVector(sf::Vector2f, sf::Vector2i); 
	static sf::Vector2f ResultVectorFloat(sf::Vector2f, sf::Vector2f);
	static float GetAngle(sf::Vector2f, float, float); 
};

