#include "Global.h";
#include "UIManager.h"
#include "Global.h"

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

	/*WinScreen text*/
	win.setPosition(Global::ScreenX / 3, Global::ScreenY / 3);
	win.setFont(font);
	win.setCharacterSize(50);
	win.setStyle(sf::Text::Bold);
	win.setFillColor(sf::Color::Red);
	win.setString("YOU WIN");

	//Load Music
	WinTheme.openFromFile("Asset/Victory.wav");
	WinTheme.setVolume(30);
	GameOverTheme.openFromFile("Asset/GameOver.wav");
	GameOverTheme.setVolume(30);
	MainTheme.openFromFile("Asset/GetDown.wav");
	MainTheme.setVolume(30);
	shootbuffer.loadFromFile("Asset/Shoot.wav"); 
	hitbuffer.loadFromFile("Asset/Hit.wav"); 
	shoot.setBuffer(shootbuffer); 
	shoot.setVolume(10);
	hit.setBuffer(hitbuffer); 
	hit.setVolume(10);
	
	
}
int UIManager::MusicManager(gameManager* gm) 
{
	////if (!gm->checkWin() && Global::_score > 0) 
	////{
	////	if (!)
	////		return -1; 
	////	MainTheme.play();
	////	MainTheme.setVolume(70);
	////	//MainTheme.setLoop(true); 
	////}
	////else 
	////{
	////	MainTheme.stop(); 
	////}
	//if (gm->checkWin())
	//{
	//	WinTheme.play();
	//	WinTheme.setVolume(50);
	//}
	//if (Global::_score < 0)
	//{
	//	if (!)
	//		return -1;
	//	GameOverTheme.play();
	//	GameOverTheme.setVolume(50);
	//}
	return 1; 
}



