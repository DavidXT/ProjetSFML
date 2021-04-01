#include "Global.h"
#include "Player.h"
#include "MathFunctions.h"
#include <iostream>
#include "gameManager.h"
#include "UIManager.h"
#include "Viseur.h"
using namespace std;


void main() {
	/* Randomize seed */
	srand(time(NULL)); 

	/*Initialise Game manager and player*/
	gameManager* gm = new gameManager(Global::BrickLineCount);
	UIManager* UI = new UIManager();
	Player* p = new Player(sf::Vector2f(40,70));

	/* variables */
	sf::Clock clock; 
	sf::RenderWindow window(sf::VideoMode(Global::ScreenX, Global::ScreenY), "MyWindow");
	sf::Event event;
	sf::Vector2f directionRotation;

	Viseur* oViseur = new Viseur(window);   
	sf::Vector2f NormalPlayerMouse; 
	sf::Vector2i oMousePosition;
	sf::Vector2i oMousePositionForRotation;

	float angle; 
	while (window.isOpen()) {
		float deltaTime = clock.restart().asSeconds(); 
		window.clear(sf::Color::Black);
		if (Global::_score >= 0) {
			if (!gm->checkWin()) {
				while (window.pollEvent(event)) {
					for (int b = 0; b < Global::nbBall; b++) {
						Ball& tmpBall = gm->getBall(b);
						/* Canon Shoot */
						if (event.type == sf::Event::MouseButtonPressed && Global::canShoot)
						{
							if (tmpBall.getShoot()) { 
								UI->shoot.play();
								Global::canShoot = false;
								tmpBall.setBallPosition(p->GetPlayerPosition());
								oMousePosition = sf::Mouse::getPosition(window);
								tmpBall.direction = MathFunctions::ResultVector(p->GetPlayerPosition(), oMousePosition);
								tmpBall.direction = MathFunctions::Normalize(tmpBall.direction);
								tmpBall.stopShoot();
							}
						}
					}
				}
				oViseur->Project(oMousePositionForRotation, p->GetPlayerPosition(), directionRotation, gm);
				for (int b = 0; b < Global::nbBall; b++) {
					Ball& tmpBall = gm->getBall(b);
					tmpBall.CheckScreen(deltaTime, p);
					oMousePositionForRotation = sf::Mouse::getPosition(window);
					directionRotation = MathFunctions::ResultVector(p->GetPlayerPosition(), oMousePositionForRotation);
					angle = MathFunctions::GetAngle(directionRotation, Global::Angle, Global::Pi);
					p->getPlayer().setRotation(angle);
					gm->GetPlatForm(0)->Collide(tmpBall, UI->hit);
					gm->GetPlatForm(1)->Collide(tmpBall, UI->hit);

					/* Brick Collision */
					for (int i = 0; i < Global::BrickLineCount; i++) {
						for (int j = 0; j < Global::BrickColumnCount; j++) {
							if (!gm->getBrick(i, j)->getDestroyed()) {
								gm->getBrick(i, j)->CheckCollision(tmpBall, UI->hit);
								window.draw(gm->getBrick(i, j)->getBrick());
							}
						}
					}
				}
				Global::canShoot = true;
				/* Setup score and number of bullet */
				UI->tScore.setString("Score : " + std::to_string(Global::_score));
				UI->tBullet.setString("Bullet : " + std::to_string(Global::dispoBall));

				/*Draw*/
				for (int b = 0; b < Global::nbBall; b++) {
					if (!gm->getBall(b).getShoot()) {
						window.draw(gm->getBall(b).getBall());
					}
				}
				window.draw(p->getPlayer());
				window.draw(UI->tScore);
				window.draw(UI->tBullet);
				if (UI->MainTheme.getStatus() != sf::SoundSource::Status::Playing) 
				{
					UI->MainTheme.play(); 
				}

				window.draw(gm->GetPlatForm(0)->GetPlateform());
				window.draw(gm->GetPlatForm(1)->GetPlateform());
				oViseur->draw();
				window.draw(p->getPlayer());
				window.display();
			}else{
				/* Draw win screen */
				if (UI->MainTheme.getStatus() == sf::SoundSource::Status::Playing)
				{
					UI->MainTheme.stop();
				}
				if (UI->WinTheme.getStatus() != sf::SoundSource::Status::Playing)
				{
					UI->WinTheme.play();
				}
				UI->tScore.setPosition(Global::ScreenX / 2.5, Global::ScreenY / 2);
				window.draw(UI->tScore);
				window.draw(UI->win);
				window.display();
			}

		}
		else {
			/* Draw lose screen */
			if (UI->MainTheme.getStatus() == sf::SoundSource::Status::Playing)
			{
				UI->MainTheme.stop();
			}
			if (UI->GameOverTheme.getStatus() != sf::SoundSource::Status::Playing)
			{
				UI->GameOverTheme.play();
			}
			UI->tScore.setString("Score : " + std::to_string(Global::_score));
			UI->tScore.setPosition(Global::ScreenX / 2, Global::ScreenY / 2);
			window.draw(UI->gameOver);
			window.draw(UI->tScore);
			window.display();
		}
	}
}