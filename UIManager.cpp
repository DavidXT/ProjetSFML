#include "Global.h";
#include "UIManager.h"

UIManager::UIManager()
{
	/*Import font*/
	font.loadFromFile("arial.ttf");

	/*Initialise text score*/
	tScore.setPosition(0, Global::ScreenY - 20);
	tScore.setOrigin(0, tScore.getCharacterSize());
	tScore.setFont(font);
	tScore.setCharacterSize(20);
	tScore.setFillColor(sf::Color::Red);

	/*Initialise bullet text*/
	tBullet.setPosition(0, Global::ScreenY);
	tBullet.setOrigin(0, tScore.getCharacterSize());
	tBullet.setFont(font);
	tBullet.setCharacterSize(20);
	tBullet.setFillColor(sf::Color::Red);

	/*Initialise game over text*/
	gameOver.setPosition(Global::ScreenX/3, Global::ScreenY/3);
	gameOver.setFont(font);
	gameOver.setCharacterSize(50);
	gameOver.setStyle(sf::Text::Bold);
	gameOver.setFillColor(sf::Color::Red);
	gameOver.setString("GAME OVER");
}



