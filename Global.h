#pragma once
#include <SFML/Graphics.hpp>
class Global {
public:

	/*Game Manager const*/
	static const int playerSpeed = 2000;
	static const int bulletSpeed = 1000;
	static const int ScreenX = 800;
	static const int ScreenY = 600;

	/*Brick level Manager*/
	static const int BrickLineCount = 5;
	static const int BrickColumnCount = ScreenX/100;
	static const int sizeXBrick = ScreenX / BrickColumnCount;
	static const int sizeYBrick = 40;

	/*Const math*/
	static const float Angle; 
	static const float Pi; 

	/*Ball manager*/
	static const int nbBall = 10;
	static const int ballSize = 10;
	static bool canShoot;
	static const int nbPlatforms = 2; 
	static int dispoBall;

	/*Var UI*/
	static int _score;
};