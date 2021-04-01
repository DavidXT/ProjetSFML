#pragma once
#include "SFML/Audio.hpp"
#include "gameManager.h"


class UIManager
{
public:
	UIManager();
	sf::Font font;
	sf::Text tScore;
	sf::Text tBullet;
	sf::Text gameOver;
	sf::Text win;
	sf::Music MainTheme; 
	sf::Music WinTheme; 
	sf::Music GameOverTheme; 
	sf::SoundBuffer shootbuffer; 
	sf::SoundBuffer hitbuffer;
	sf::Sound shoot; 
	sf::Sound hit; 
	int MusicManager(gameManager* gm); 
private:
};

