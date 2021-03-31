#include "Global.h"
#include "Player.h"
#include "MathFunctions.h"
#include <iostream>
#include "gameManager.h"
using namespace std;
#include "Viseur.h"

void main() {
	/* Randomize seed */
	srand(time(NULL)); 

	/*Initialise Game manager and player*/
	gameManager* gm = new gameManager(Global::level);
	Player* p = new Player(sf::Vector2f(40,70));

	/*Initialise text score*/
	sf::Text tScore;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	tScore.setPosition(0, Global::ScreenY);
	tScore.setOrigin(0, tScore.getCharacterSize());
	tScore.setFont(font);
	tScore.setCharacterSize(30);
	tScore.setStyle(sf::Text::Bold);
	tScore.setFillColor(sf::Color::Red);

	sf::Clock clock; 
	sf::RenderWindow window(sf::VideoMode(Global::ScreenX, Global::ScreenY), "MyWindow");
	sf::Event event;
	sf::Vector2f directionRotation;
	gameManager* gm = new gameManager(Global::level);
	Player* p = new Player(window, gm);
	Viseur* oViseur = new Viseur(window);  
	sf::Vector2f direction;
	sf::Vector2f directionRotation; 
	sf::Vector2f NormalPlayerMouse; 
	sf::Vector2i oMousePosition;
	sf::Vector2i oMousePositionForRotation;

	float angle; 
	while (window.isOpen()) {
		float deltaTime = clock.restart().asSeconds();
		window.clear(sf::Color::Black);

		while (window.pollEvent(event)) {
			for (int b = 0; b < Global::nbBall; b++) {

				/* Canon mouvement */
				if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
				{
					p->moveLeft(deltaTime);
					if (gm->getBall(b).getShoot()) {
						gm->getBall(b).setBallPosition(p->GetPlayerPosition());
					}
				}
				if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
				{
					p->moveRight(deltaTime);
					if (gm->getBall(b).getShoot()) {
						gm->getBall(b).setBallPosition(p->GetPlayerPosition());
					}
				}

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
			gm->getBall(b).CheckScreen(deltaTime,p);

			oMousePositionForRotation = sf::Mouse::getPosition(window);
			directionRotation = MathFunctions::ResultVector(p->GetPlayerPosition(), oMousePositionForRotation);
			angle = MathFunctions::GetAngle(directionRotation, Global::Angle, Global::Pi);
			p->getPlayer().setRotation(angle);

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
		tScore.setString("Score : " + std::to_string(Global::_score));

		/*Draw*/
		for (int b = 0; b < Global::nbBall; b++) {
			if (!gm->getBall(b).getShoot()) {
				window.draw(gm->getBall(b).getBall());
			}
		}
		window.draw(p->getPlayer());
		window.draw(tScore);
		gm->GetPlatForm(0)->Collide(b, isNotCollide, direction); 
		window.draw(gm->GetPlatForm(0)->GetPlateform()); 
		gm->GetPlatForm(1)->Collide(b, isNotCollide, direction);
		window.draw(gm->GetPlatForm(1)->GetPlateform());
		window.draw(b->getBall());
		oViseur->draw();
		window.draw(p->getPlayer()); 
		window.display();
	}
}