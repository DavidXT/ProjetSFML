#include "Global.h"
#include "MathFunctions.h"

/* Function for normalization of a vector*/
sf::Vector2f MathFunctions::Normalize(sf::Vector2f vector) {
	double norme = sqrt(vector.x * vector.x + vector.y * vector.y); 
	vector.x = vector.x / norme; 
	vector.y = vector.y / norme; 
	return vector; 
}

/* Function to get Normal of a vector*/
float MathFunctions::Norme(sf::Vector2f vector) {
	double norme = sqrt(vector.x * vector.x + vector.y * vector.y);
	return norme; 
}

/* Result between 2 vector */
sf::Vector2f MathFunctions::ResultVector(sf::Vector2f A, sf::Vector2i B) {
	sf::Vector2f C; 
	C.x = B.x - A.x; 
	C.y = B.y - A.y; 
	return C; 
}

/* Result between 2 vector as float */
sf::Vector2f MathFunctions::ResultVectorFloat(sf::Vector2f A, sf::Vector2f B) {
	sf::Vector2f C;
	C.x = B.x - A.x;
	C.y = B.y - A.y;
	return C;
}
/* Get angle with a vector */
float MathFunctions::GetAngle(sf::Vector2f A, float globalangle, float pi) 
{
	float coeff = globalangle / pi; 
	float angle = atan2(A.x, A.y) * coeff * (-1); 
	return angle; 
}