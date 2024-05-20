#include "shield.h"

Shield::Shield(std::string title, std::string description) :
	Weapon(title, description, 1, 1, 20, 50)
{
}

Shield::~Shield()
{
}
