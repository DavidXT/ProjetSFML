#include "Global.h"
#include "Ball.h"
#include "Player.h"
#include "MathFunctions.h"
#include <iostream>

void main() {
	Player* p = new Player();
	Ball* b = new Ball();
	sf::Clock clock; 
	sf::RenderWindow window(sf::VideoMode(Global::ScreenX, Global::ScreenY), "MyWindow");
	sf::Vector2f direction;
	sf::Vector2i oMousePosition;
	sf::Event event;
	sf::Vector2f o_MouseRot; 
	sf::Vector2f o_NormalCanon; 
	float angle; 
	while (window.isOpen()) {
		float deltaTime = clock.restart().asSeconds();
		window.clear(sf::Color::Black);


		while (window.pollEvent(event)) {
			
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up))
			{
				p->moveUp(deltaTime);
			}
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down))
			{
				p->moveDown(deltaTime);
			}
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
			{
				p->moveLeft(deltaTime);
			}
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
			{
				p->moveRight(deltaTime);
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
			//b->getBall().move(fX, fY); 
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
			direction.y *= -1;
		}
		
			
		window.draw(p->getPlayer());
		window.draw(b->getBall());
		window.display();
	}
}