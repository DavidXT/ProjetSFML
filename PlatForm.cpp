#include "Global.h"
#include "PlatForm.h"
#include <iostream>
// Constructeur de la PlateForme
PlatForm::PlatForm(float _CoeffPos)
{
	CoeffPos = _CoeffPos;
	f.setSize(sf::Vector2f(120, 40));
	f.setOrigin(f.getSize().x * 0.5, f.getSize().y * 0.5);
	f.setPosition(Global::ScreenX / 4 * CoeffPos, Global::ScreenY);
	BoxCollision = f.getGlobalBounds();
}
// Fonction qui retourn la shape de la plateform
sf::RectangleShape& PlatForm::GetPlateform()
{
	return f;
}
// Fonction de collision entre la plateforme et la balle 
void PlatForm::Collide(Ball& b, sf::Sound& hit)
{
		sf::FloatRect BallRect = b.getBall().getGlobalBounds();
		// on récupère la plateforme
		sf::FloatRect tempRect = GetPlateform().getGlobalBounds();
		// si la balle touche un des trois côtés visibles de la plateforme, on la revoie 
		if (BallRect.intersects(tempRect) && b.getIsNotCollide())
		{
			// pour que la balle ne touche deux fois la plateforme
			b.Collide();
			float t_collision = BallRect.top + BallRect.height - tempRect.top;
			float l_collision = BallRect.left + BallRect.width - tempRect.left;
			float r_collision = tempRect.left + tempRect.width - BallRect.left;
			if (t_collision <= l_collision && t_collision <= r_collision) 
			{
				b.direction.y *= -1;
				hit.play(); 
			}
			if (l_collision <= r_collision && l_collision <= t_collision || r_collision <= l_collision && r_collision <= t_collision)
			{
				b.direction.x *= -1;
				hit.play(); 
			}
		}
		else 
		{
			// pour que la balle puisse retoucher la plateforme
			b.StopCollide();
		}

}

