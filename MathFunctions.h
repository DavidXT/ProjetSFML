#pragma once
#include <SFML/Graphics.hpp>
#include "Global.h"
class MathFunctions
{
public : 
	static sf::Vector2f Normalize(sf::Vector2f); 
	static float Norme(sf::Vector2f); 
	static sf::Vector2f ResultVector(sf::Vector2f, sf::Vector2i); 
	static sf::Vector2f ResultVectorFloat(sf::Vector2f, sf::Vector2f);
	static float GetAngle(sf::Vector2f, float, float); 
	static float ToRadian(float degree) { return (Global::Pi / Global::Angle) * degree;  }
	static float GetYComposante(float, sf::Vector2f, sf::Vector2f); 
	static inline float dCos(float degree) { return cos(ToRadian(degree));  }
	static inline float dSin(float degree) { return sin(ToRadian(degree));  }
};

