#include "Global.h"
#include "MathFunctions.h"
// Fonctions pour normaliser un vector 
sf::Vector2f MathFunctions::Normalize(sf::Vector2f vector) {
	double norme = sqrt(vector.x * vector.x + vector.y * vector.y); 
	vector.x = vector.x / norme; 
	vector.y = vector.y / norme; 
	return vector; 
}
// Fonction pour récuperer la norme d'un vecteur 
float MathFunctions::Norme(sf::Vector2f vector) {
	double norme = sqrt(vector.x * vector.x + vector.y * vector.y);
	return norme; 
}
//Fonction pour trouver le vecteur résultant entre un vecfloat et un vecint ( essentiellement pour la souris)
sf::Vector2f MathFunctions::ResultVector(sf::Vector2f A, sf::Vector2i B) {
	sf::Vector2f C; 
	C.x = B.x - A.x; 
	C.y = B.y - A.y; 
	return C; 
}
// Fonction pour trouver le vecteur résultant entre deux vecfloat
sf::Vector2f MathFunctions::ResultVectorFloat(sf::Vector2f A, sf::Vector2f B) {
	sf::Vector2f C;
	C.x = B.x - A.x;
	C.y = B.y - A.y;
	return C;
}
// fonction pour récuperer l'orientation d'un vecteur 
float MathFunctions::GetAngle(sf::Vector2f A, float globalangle, float pi) 
{
	float coeff = globalangle / pi; 
	float angle = atan2(A.x, A.y) * coeff * (-1); 
	return angle; 
}