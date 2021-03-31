#pragma once

class Global {
public:
	static const int playerSpeed = 2000;
	static const int bulletSpeed = 1000; 
	static const int ScreenX = 1500;
	static const int ScreenY = 800;
	static const int level = 2;
	static const int nbBrick = ScreenY/100;
	static const int ScreenXLimit = ScreenX - ScreenX/10;
	static const int sizeXBrick = ScreenXLimit / nbBrick;
	static const int sizeYBrick = 50;
	static const float Angle; 
	static const float Pi; 
	static bool canShoot;
	static const int nbPlatforms = 2; 


};