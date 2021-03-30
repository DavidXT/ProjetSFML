#pragma once
#include <SFML/Graphics.hpp>

class Global {
public:
	static const int playerSpeed = 2000;
	static const int bulletSpeed = 1000;
	static const int ScreenX = 800;
	static const int ScreenY = 600;
	static const int level = 5;
	static const int nbBrick = ScreenX/100;
	static const int sizeXBrick = ScreenX / nbBrick;
	static const int sizeYBrick = 40;
	static const float Angle; 
	static const float Pi; 
	static const int nbBall = 10;
	static const int ballSize = 10;
	static bool canShoot;
};