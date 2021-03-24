#pragma once

class Global {
public:
	static const int playerSpeed = 500;
	static const int bulletSpeed = 300;
	static const int ScreenX = 1500;
	static const int ScreenY = 800;
	static const int level = 3;
	static const int nbBrick = ScreenY/100;
	static const int ScreenXLimit = ScreenX - 125;
	static const int sizeXBrick = ScreenXLimit / nbBrick;
	static const int sizeYBrick = 50;
	static bool canShoot;


};