#include "PlatForm.h"
#include "Global.h"

PlatForm::PlatForm(float _CoeffPos)
{
	CoeffPos = _CoeffPos; 
	f.setSize(sf::Vector2f(120, 40)); 
	f.setOrigin(f.getSize().x * 0.5, f.getSize().y * 0.5); 
	f.setPosition(Global::ScreenX / 4 * CoeffPos, Global::ScreenY); 
}
