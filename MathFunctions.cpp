#include "MathFunctions.h"
sf::Vector2f MathFunctions::Normalize(sf::Vector2f vector) {
	double norme = sqrt(vector.x * vector.x + vector.y * vector.y); 
	vector.x = vector.x / norme; 
	vector.y = vector.y / norme; 
	return vector; 
}
float MathFunctions::Norme(sf::Vector2f vector) {
	double norme = sqrt(vector.x * vector.x + vector.y * vector.y);
	return norme; 
}
sf::Vector2f MathFunctions::ResultVector(sf::Vector2f A, sf::Vector2i B) {
	sf::Vector2f C; 
	C.x = B.x - A.x; 
	C.y = B.y - A.y; 
	return C; 
}
sf::Vector2f MathFunctions::ResultVectorFloat(sf::Vector2f A, sf::Vector2f B) {
	sf::Vector2f C;
	C.x = B.x - A.x;
	C.y = B.y - A.y;
	return C;
}
float MathFunctions::GetAngle(sf::Vector2f A, float globalangle, float pi) 
{
	float coeff = globalangle / pi; 
	float angle = atan2(A.x, A.y) * coeff * (-1); 
	return angle; 
}
float MathFunctions::GetYComposante(float angle, sf::Vector2f A, sf::Vector2f B) {
	sf::Vector2f C = ResultVectorFloat(A, B); 
	float normeC = Norme(C); 
	float vector = normeC / tan(angle); 
	return vector;
}