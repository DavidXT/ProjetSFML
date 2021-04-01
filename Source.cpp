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
	gameManager* gm = new gameManager(Global::level);
	UIManager* UI = new UIManager();
	Player* p = new Player(sf::Vector2f(40,70));

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
			while (window.pollEvent(event)) {
				for (int b = 0; b < Global::nbBall; b++) {

					/* Canon Shoot */
					if (event.type == sf::Event::MouseButtonPressed && Global::canShoot)
					{
						if (gm->getBall(b).getShoot()) {
							Global::canShoot = false;
							gm->getBall(b).setBallPosition(p->GetPlayerPosition());
							oMousePosition = sf::Mouse::getPosition(window);
							gm->getBall(b).direction = MathFunctions::ResultVector(p->GetPlayerPosition(), oMousePosition);
							gm->getBall(b).direction = MathFunctions::Normalize(gm->getBall(b).direction);
							gm->getBall(b).stopShoot();
						}
					}
				}
			}
			for (int b = 0; b < Global::nbBall; b++) {
				gm->getBall(b).CheckScreen(deltaTime, p);
				oMousePositionForRotation = sf::Mouse::getPosition(window);
				directionRotation = MathFunctions::ResultVector(p->GetPlayerPosition(), oMousePositionForRotation);
				angle = MathFunctions::GetAngle(directionRotation, Global::Angle, Global::Pi);
				p->getPlayer().setRotation(angle);
				gm->GetPlatForm(0)->Collide(gm->getBall(b));
				gm->GetPlatForm(1)->Collide(gm->getBall(b));
				/* Brick Collision */
				for (int i = 0; i < Global::level; i++) {
					for (int j = 0; j < Global::nbBrick; j++) {
						if (!gm->getBrick(i, j)->getDestroyed()) {
							gm->getBrick(i, j)->CheckCollision(gm->getBall(b));
							window.draw(gm->getBrick(i, j)->getBrick());
						}
					}
				}
			}
			Global::canShoot = true;
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
			window.draw(gm->GetPlatForm(0)->GetPlateform());
			window.draw(gm->GetPlatForm(1)->GetPlateform());
			oViseur->draw();
			window.draw(p->getPlayer());
			window.display();
		}
		else {
			window.draw(UI->gameOver);
			window.display();
		}
	}
}