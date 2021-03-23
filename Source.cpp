#include "Global.h"
#include "Ball.h"
#include "Player.h"

void main() {
	Player* p = new Player();
	Ball* b = new Ball();
	sf::Clock clock; 
	sf::RenderWindow window(sf::VideoMode(Global::ScreenX, Global::ScreenY), "MyWindow");
	sf::Vector2f direction;
	sf::Event event;
	float deltaTime = clock.restart().asSeconds();
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			window.clear(sf::Color::Black);
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
				b->setBallPosition(p->getPlayer());
			}
		}
		if (!Global::canShoot) {
			window.draw(b->getBall());
			b->moveBall(deltaTime, direction);
			if (b->getBall().getPosition().x < 0) {
				Global::canShoot = true;
				b->setBallPosition(p->getPlayer());
			}
			if (b->getBall().getPosition().y < 0) {
				Global::canShoot = true;
				b->setBallPosition(p->getPlayer());
			}
		}
		window.draw(p->getPlayer());
		window.display();
	}
}