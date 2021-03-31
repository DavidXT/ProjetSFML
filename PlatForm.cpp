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
void PlatForm::Collide(Ball& b) 
{
	
		sf::Shape& tempRect = GetPlateform(); 
		if (b.getBall().getGlobalBounds().intersects(tempRect.getGlobalBounds()) && b.getIsNotCollide())
		{
			float t_collision = b.getBall().getGlobalBounds().top + b.getBall().getGlobalBounds().height - tempRect.getGlobalBounds().top;
			float l_collision = b.getBall().getGlobalBounds().left + b.getBall().getGlobalBounds().width - tempRect.getGlobalBounds().left;
			float r_collision = tempRect.getGlobalBounds().left + tempRect.getGlobalBounds().width - b.getBall().getGlobalBounds().left;
			if (t_collision <= l_collision && t_collision <= r_collision) 
			{
				if (l_collision <= r_collision && l_collision <= t_collision || r_collision <= l_collision && r_collision <= t_collision) 
				{
					b.direction.x *= -1;
				}
				b.direction.y *= -1;
			}
			if (l_collision <= r_collision && l_collision <= t_collision || r_collision <= l_collision && r_collision <= t_collision)
			{
				b.direction.x *= -1;
			}
			b.Collide();
		}
		else 
		{
			b.StopCollide();
		}

}

