#include "Global.h"
#include "PlatForm.h"
#include <iostream>

PlatForm::PlatForm(float _CoeffPos)
{
	CoeffPos = _CoeffPos;
	f.setSize(sf::Vector2f(120, 40));
	f.setOrigin(f.getSize().x * 0.5, f.getSize().y * 0.5);
	f.setPosition(Global::ScreenX / 4 * CoeffPos, Global::ScreenY);
	BoxCollision = f.getGlobalBounds();
}
sf::RectangleShape& PlatForm::GetPlateform()
{
	return f;
}
void PlatForm::Collide(Ball& b)
{
	sf::Shape& tmpRect = GetPlateform();
	if (b.getBall().getGlobalBounds().intersects(tmpRect.getGlobalBounds()) && b.getIsNotCollide()) {
		float b_collision = tmpRect.getGlobalBounds().top + tmpRect.getGlobalBounds().height - b.getBall().getGlobalBounds().top; //Bottom 
		float t_collision = b.getBall().getGlobalBounds().top + b.getBall().getGlobalBounds().height - tmpRect.getGlobalBounds().top; //Top
		float l_collision = b.getBall().getGlobalBounds().left + b.getBall().getGlobalBounds().width - tmpRect.getGlobalBounds().left; //Left
		float r_collision = tmpRect.getGlobalBounds().left + tmpRect.getGlobalBounds().width - b.getBall().getGlobalBounds().left; //Right
		if (t_collision <= b_collision && t_collision <= l_collision && t_collision <= r_collision || b_collision <= t_collision && b_collision <= l_collision && b_collision <= r_collision)
		{
			if (l_collision <= r_collision && l_collision <= t_collision && l_collision <= b_collision || r_collision <= l_collision && r_collision <= t_collision && r_collision <= b_collision)
			{
				b.direction.x *= -1;
			}
			b.direction.y *= -1;
		}
		if (l_collision <= r_collision && l_collision <= t_collision && l_collision <= b_collision || r_collision <= l_collision && r_collision <= t_collision && r_collision <= b_collision)
		{
			b.direction.x *= -1;
		}
		b.Collide();
	}
	else {
		b.StopCollide();
	}
}

