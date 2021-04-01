#include "Viseur.h"
#include "Global.h"
#include <iostream>
#include "MathFunctions.h"
#include "gameManager.h"
// Constructeur du viseur 
Viseur::Viseur(sf::RenderWindow& renderWindow) : window(renderWindow)
{

}
// Fonction qui va gérer le rayon du viseur 
void Viseur::Project(sf::Vector2i MousePosition, sf::Vector2f PlayerPosition, sf::Vector2f directionSecondRay, gameManager* gm)
{
	// Calcul du rayon du viseur comme d'une fonction afine
	float RayLength = 200; 
	directionSecondRay = MathFunctions::Normalize(directionSecondRay);
	sf::Vector2f oMouse = (sf::Vector2f)MousePosition; 
	pente = (PlayerPosition.y - oMouse.y)/ (PlayerPosition.x - oMouse.x); 
	origin = oMouse.y - pente * oMouse.x;
	line[0] = PlayerPosition;  
	float XLeft = 0; 
	float XRight = Global::ScreenX;
	float YTop = 0; 
	float YLeft = pente * XLeft + origin; 
	float YRight = pente * XRight + origin;
	float XTop = ( YTop - origin )/ pente;
	// Réaction du viseur au contatc de l'écran
	//sur le haut de l'ecran 
	if (XTop > XLeft && XTop < XRight) 
	{
		line[1].position.x = XTop; 
		line[1].position.y = YTop; 
		line[2].position = line[1].position;
		float pente2 = -pente; 
		float origin2 = -MousePosition.y - pente2 * MousePosition.x; ;
		line[3].position.x = line[2].position.x + RayLength * directionSecondRay.x;
		line[3].position.y = line[2].position.y + RayLength * directionSecondRay.y * (-1); 
	}
	//Sur la gauche de l'ecran 
	else if (YLeft > YTop && YLeft < YRight) 
	{
		line[1].position.x = XLeft; 
		line[1].position.y = YLeft;
		line[2].position = line[1].position; 
		line[3].position.x = line[2].position.x + RayLength * directionSecondRay.x * (-1);
		line[3].position.y = line[2].position.y + RayLength * directionSecondRay.y;
	}
	// Sur la droite de l'ecran
	else if (YRight < YLeft && YRight > YTop)
	{
		line[1].position.x = XRight;
		line[1].position.y = YRight;
		line[2].position = line[1].position;
		line[3].position.x = line[2].position.x + RayLength * directionSecondRay.x * (-1);
		line[3].position.y = line[2].position.y + RayLength * directionSecondRay.y ;
	} 
	// Réaction du viseur aux contacts des briques
	StopRay = false;
	for (int i = Global::BrickLineCount -1 ; i >= 0; i--)
	{
		if (StopRay == true) { 
			break;
		}
		for (int j = Global::BrickColumnCount - 1; j >= 0 ; j--)
		{
			// Même technique que pour les bords de l'ecran 
			if (gm->getBrick(i, j)->getDestroyed())
				continue;
			sf::FloatRect BrickRect = gm->getBrick(i, j)->getBrick().getGlobalBounds();
			float Ybot = BrickRect.top + BrickRect.height;
			float Ytop = BrickRect.top;
			float Xbot = (Ybot - origin) / pente;
			float Xleft = BrickRect.left;
			float Xright = BrickRect.left + BrickRect.width;
			float Yleft = pente * Xleft + origin;
			float Yright = pente * Xright + origin;
			// Réaction sur le coté gauche de la brique 
			if (Yleft > Ytop && Yleft < Ybot && StopRay == false)
			{
				StopRay = true;
				line[1].position.x = Xleft;
				line[1].position.y = Yleft;
				line[2].position = line[1].position;
				line[3].position.x = line[2].position.x + RayLength * directionSecondRay.x * (-1);
				line[3].position.y = line[2].position.y + RayLength * directionSecondRay.y;
				break;
			}
			// Réaction sur le coté droit de la brique
			else if (Yright > Ytop && Yright < Ybot && StopRay == false)
			{
				StopRay = true;
				line[1].position.x = Xright;
				line[1].position.y = Yright;
				line[2].position = line[1].position;
				line[3].position.x = line[2].position.x + RayLength * directionSecondRay.x * (-1);
				line[3].position.y = line[2].position.y + RayLength * directionSecondRay.y;
				break;
			}
			//Réaction sur le bas de la brique
			else if (Xbot > Xleft && Xbot < Xright && StopRay == false)
			{
				StopRay = true; 
				line[1].position.x = Xbot;
				line[1].position.y = Ybot;
				line[2].position = line[1].position;
				line[3].position.x = line[2].position.x + RayLength * directionSecondRay.x;
				line[3].position.y = line[2].position.y + RayLength * directionSecondRay.y * (-1);
				
				break;
			}
			
			
		}
	}
}
// Dessin des lignes du viseur 
void Viseur::draw() {

	line[0].color = sf::Color::White; 
	line[1].color = sf::Color::White; 
	line[2].color = sf::Color::White; 
	line[3].color = sf::Color::White; 
	window.draw(line, 4, sf::Lines); 
}

