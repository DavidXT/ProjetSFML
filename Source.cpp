#include "Global.h"
#include "Ball.h"
#include "Player.h"
#include "MathFunctions.h"
#include <iostream>
#include "gameManager.h"

void main() {
	srand(time(NULL)); 
	gameManager* gm = new gameManager(Global::level);
	Player* p = new Player(sf::Vector2f(40,70));
	sf::Clock clock; 
	sf::RenderWindow window(sf::VideoMode(Global::ScreenX, Global::ScreenY), "MyWindow");
	sf::Event event;
	sf::Vector2f directionRotation;
	sf::Vector2i oMousePosition;
	sf::Vector2i oMousePositionForRotation;
	float angle; 
	while (window.isOpen()) {
		float deltaTime = clock.restart().asSeconds();
		window.clear(sf::Color::Black);
		while (window.pollEvent(event)) {
			for (int b = 0; b < Global::nbBall; b++) {
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
			if (!gm->getBall(b).getShoot()) {
				const sf::Vector2f& oPosition = gm->getBall(b).getBall().getPosition();
				float fX = oPosition.x + (gm->getBall(b).direction.x * (float)Global::bulletSpeed * deltaTime);
				float fY = oPosition.y + (gm->getBall(b).direction.y * (float)Global::bulletSpeed * deltaTime);
				gm->getBall(b).getBall().setPosition(fX, fY);
				if (gm->getBall(b).getBall().getGlobalBounds().left < 0)
				{
					gm->getBall(b).direction.x *= -1;
				}
				if (gm->getBall(b).getBall().getGlobalBounds().left + gm->getBall(b).getBall().getGlobalBounds().width > Global::ScreenX)
				{
					gm->getBall(b).direction.x *= -1;
				}
				if (gm->getBall(b).getBall().getGlobalBounds().top < 0)
				{
					gm->getBall(b).direction.y *= -1;
				}
				if (gm->getBall(b).getBall().getGlobalBounds().top + gm->getBall(b).getBall().getGlobalBounds().height > Global::ScreenY)
				{
					gm->getBall(b).setBallPosition(p->GetPlayerPosition());
					gm->getBall(b).reload();
				}
			}


			oMousePositionForRotation = sf::Mouse::getPosition(window);
			directionRotation = MathFunctions::ResultVector(p->GetPlayerPosition(), oMousePositionForRotation);
			angle = MathFunctions::GetAngle(directionRotation, Global::Angle, Global::Pi);
			p->getPlayer().setRotation(angle);

			for (int i = 0; i < Global::level; i++) {
				for (int j = 0; j < Global::nbBrick; j++) {
					sf::Shape& tmpRect = gm->getBrick(i, j)->getBrick();
					if (!gm->getBrick(i, j)->getDestroyed()) {
						if (gm->getBall(b).getBall().getGlobalBounds().intersects(tmpRect.getGlobalBounds()) && gm->getBall(b).getIsNotCollide()) {
							float b_collision = tmpRect.getGlobalBounds().top + tmpRect.getGlobalBounds().height - gm->getBall(b).getBall().getGlobalBounds().top; //Bottom 
							float t_collision = gm->getBall(b).getBall().getGlobalBounds().top + gm->getBall(b).getBall().getGlobalBounds().height - tmpRect.getGlobalBounds().top; //Top
							float l_collision = gm->getBall(b).getBall().getGlobalBounds().left + gm->getBall(b).getBall().getGlobalBounds().width - tmpRect.getGlobalBounds().left; //Left
							float r_collision = tmpRect.getGlobalBounds().left + tmpRect.getGlobalBounds().width - gm->getBall(b).getBall().getGlobalBounds().left; //Right
							if (t_collision <= b_collision && t_collision <= l_collision && t_collision <= r_collision || b_collision <= t_collision && b_collision <= l_collision && b_collision <= r_collision)
							{
								if (l_collision <= r_collision && l_collision <= t_collision && l_collision <= b_collision || r_collision <= l_collision && r_collision <= t_collision && r_collision <= b_collision)
								{
									gm->getBall(b).direction.x *= -1;
								}
								gm->getBall(b).direction.y *= -1;
							}
							if (l_collision <= r_collision && l_collision <= t_collision && l_collision <= b_collision || r_collision <= l_collision && r_collision <= t_collision && r_collision <= b_collision)
							{
								gm->getBall(b).direction.x *= -1;
							}
							gm->getBall(b).Collide();
							gm->getBrick(i, j)->getDamage();
						}
						else {
							gm->getBall(b).StopCollide();
						}
						window.draw(tmpRect);
					}
				}
			}
		}
		Global::canShoot = true;
		for (int b = 0; b < Global::nbBall; b++) {
			if (!gm->getBall(b).getShoot()) {
				window.draw(gm->getBall(b).getBall());
			}
		}
		window.draw(p->getPlayer());
		window.display();
	}
}