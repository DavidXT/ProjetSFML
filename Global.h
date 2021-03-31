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
	static const int level = 5;
	static const int nbBrick = ScreenX/100;
	static const int sizeXBrick = ScreenX / nbBrick;
	static const int sizeYBrick = 40;

	/*Const math*/
	static const float Angle; 
	static const float Pi; 

	/*Ball manager*/
	static const int nbBall = 10;
	static const int ballSize = 10;
	static bool canShoot;

	/*Var UI*/
	static int _score;
};