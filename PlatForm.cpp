#include "PlatForm.h"
#include "Global.h"
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
void PlatForm::Collide(Ball* b, bool isNotCollide, sf::Vector2f BallDirection) 
{
	
		sf::RectangleShape tempRect = GetPlateform(); 
		if (b->getBall().getGlobalBounds().intersects(tempRect.getGlobalBounds()) && isNotCollide) 
		{
			float t_collision = b->getBall().getGlobalBounds().top + b->getBall().getGlobalBounds().height - tempRect.getGlobalBounds().top; 
			float l_collision = b->getBall().getGlobalBounds().left + b->getBall().getGlobalBounds().width - tempRect.getGlobalBounds().left;
			float r_collision = tempRect.getGlobalBounds().left + tempRect.getGlobalBounds().width - b->getBall().getGlobalBounds().left; 
			if (t_collision <= l_collision && t_collision <= r_collision) 
			{
				if (l_collision <= r_collision && l_collision <= t_collision || r_collision <= l_collision && r_collision <= t_collision) 
				{
					BallDirection.x *= -1; 
				} 
				BallDirection.y *= -1; 
			}
			if (l_collision <= r_collision && l_collision <= t_collision || r_collision <= l_collision && r_collision <= t_collision)
			{
				BallDirection.x *= -1;
			}
			isNotCollide = false; 
		}
		else 
		{
			isNotCollide = true; 
		}
}

