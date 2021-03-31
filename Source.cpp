#include "Global.h"
#include "Ball.h"
#include "Player.h"
#include "MathFunctions.h"
#include <iostream>
#include "gameManager.h"
#include "Viseur.h"

void main() {
	srand(time(NULL)); 
	Ball* b = new Ball();
	sf::Clock clock; 
	sf::RenderWindow window(sf::VideoMode(Global::ScreenX, Global::ScreenY), "MyWindow");
	gameManager* gm = new gameManager(Global::level);
	Player* p = new Player(window, gm);
	Viseur* oViseur = new Viseur(window);  
	sf::Vector2f direction;
	sf::Vector2f directionRotation; 
	sf::Vector2f NormalPlayerMouse; 
	sf::Vector2i oMousePosition;
	sf::Vector2i oMousePositionForRotation; 
	sf::Event event;
	sf::Vector2f o_MouseRot; 
	sf::Vector2f o_NormalCanon; 
	bool isNotCollide = true;
	float angle; 
	while (window.isOpen()) {
		float deltaTime = clock.restart().asSeconds();
		window.clear(sf::Color::Black);
		while (window.pollEvent(event)) {
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
			{
				p->moveLeft(deltaTime);
				b->setBallPosition(p->GetPlayerPosition());
			}
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
			{
				p->moveRight(deltaTime);
				b->setBallPosition(p->GetPlayerPosition());
			}
			if (event.type == sf::Event::MouseButtonPressed && Global::canShoot)
			{
				Global::canShoot = false;
				b->setBallPosition(p->GetPlayerPosition());
				oMousePosition = sf::Mouse::getPosition(window);
				direction = MathFunctions::ResultVector(p->GetPlayerPosition(), oMousePosition);
				direction = MathFunctions::Normalize(direction); 
			}
		}
		if (!Global::canShoot)
		{
			const sf::Vector2f& oPosition = b->getBall().getPosition(); 
			float fX = oPosition.x + (direction.x * (float) Global::bulletSpeed * deltaTime); 
			float fY = oPosition.y + (direction.y * (float) Global::bulletSpeed * deltaTime);
			b->getBall().setPosition(fX, fY);
		}
		if (b->getBall().getGlobalBounds().left < 0) 
		{
			direction.x *= -1;
		}
		if (b->getBall().getGlobalBounds().left + b->getBall().getGlobalBounds().width > Global::ScreenX) 
		{
			direction.x *= -1; 
		}
		if (b->getBall().getGlobalBounds().top < 0) 
		{
			direction.y *= -1; 
		}
		if (b->getBall().getGlobalBounds().top + b->getBall().getGlobalBounds().height > Global::ScreenY)
		{
			//direction.y *= -1;
			b->setBallPosition(p->GetPlayerPosition());
			Global::canShoot = true;
		}
		oMousePositionForRotation = sf::Mouse::getPosition(window);
		directionRotation = MathFunctions::ResultVector(p->GetPlayerPosition(), oMousePositionForRotation);
		directionRotation = MathFunctions::Normalize(directionRotation); 
		p->angle = MathFunctions::GetAngle(directionRotation, Global::Angle, Global::Pi); 
		oViseur->Project(oMousePositionForRotation, p->GetPlayerPosition(), directionRotation); 
		p->getPlayer().setRotation(p->angle);

		for (int i = 0; i < Global::level; i++) {
			for (int j = 0; j < Global::nbBrick; j++) {
				sf::RectangleShape tmpRect = gm->getBrick(i, j)->getBrick();
				if (!gm->getBrick(i, j)->getDestroyed()) {
					if (b->getBall().getGlobalBounds().intersects(tmpRect.getGlobalBounds()) && isNotCollide) {
						float b_collision = tmpRect.getGlobalBounds().top + tmpRect.getGlobalBounds().height - b->getBall().getGlobalBounds().top; //Bottom 
						float t_collision = b->getBall().getGlobalBounds().top + b->getBall().getGlobalBounds().height - tmpRect.getGlobalBounds().top; //Top
						float l_collision = b->getBall().getGlobalBounds().left + b->getBall().getGlobalBounds().width - tmpRect.getGlobalBounds().left; //Left
						float r_collision = tmpRect.getGlobalBounds().left + tmpRect.getGlobalBounds().width - b->getBall().getGlobalBounds().left; //Right
						if (t_collision <= b_collision && t_collision <= l_collision && t_collision <= r_collision || b_collision <= t_collision && b_collision <= l_collision && b_collision <= r_collision)
						{
							if (l_collision <= r_collision && l_collision <= t_collision && l_collision <= b_collision || r_collision <= l_collision && r_collision <= t_collision && r_collision <= b_collision)
							{
								direction.x *= -1;
							}
							direction.y *= -1;
						}
						if (l_collision <= r_collision && l_collision <= t_collision && l_collision <= b_collision || r_collision <= l_collision && r_collision <= t_collision && r_collision <= b_collision)
						{
							direction.x *= -1;						
						}
						isNotCollide = false;
						gm->getBrick(i, j)->getDamage();
					}
					else {
						isNotCollide = true;
					}
					window.draw(tmpRect);
				}
			}
		}
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