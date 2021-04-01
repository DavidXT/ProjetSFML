#include "Global.h"
#include "PlatForm.h"
#include <iostream>

/* Constructor */
PlatForm::PlatForm(float _CoeffPos)
{
	CoeffPos = _CoeffPos;
	f.setSize(sf::Vector2f(120, 40));
	f.setOrigin(f.getSize().x * 0.5, f.getSize().y * 0.5);
	f.setPosition(Global::ScreenX / 4 * CoeffPos, Global::ScreenY);
	BoxCollision = f.getGlobalBounds();
}
/* Return shape */
sf::RectangleShape& PlatForm::GetPlateform()
{
	return f;
}

/* Check collision with a ball */
void PlatForm::Collide(Ball& b) 
{
		sf::FloatRect BallRect = b.getBall().getGlobalBounds();
		sf::FloatRect tempRect = GetPlateform().getGlobalBounds();
		if (BallRect.intersects(tempRect) && b.getIsNotCollide())
		{
			b.Collide();
			float t_collision = BallRect.top + BallRect.height - tempRect.top;
			float l_collision = BallRect.left + BallRect.width - tempRect.left;
			float r_collision = tempRect.left + tempRect.width - BallRect.left;
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
		}
		else 
		{
			b.StopCollide();
		}

}

