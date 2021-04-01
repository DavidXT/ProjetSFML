#include "Global.h"

bool Global::canShoot = true;
const float Global::Angle = 180; 
const float Global::Pi = 3.14; 
int Global::_score = 100;
int Global::dispoBall = Global::nbBall;
bool Global::isWin = false;

std::string Global::map[Global::BrickLineCount][Global::BrickColumnCount] =
{ 	"X","X" ,"O","O","O","O","X","X",
	"X","O" ,"X","X","X","X","O","X",
	"X","O" ,"X","X","X","X","O","X",
	"X","O" ,"X","X","X","X","O","X",
	"X","X" ,"O","O","O","O","X","X" };
