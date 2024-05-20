#include "sword.h"

Sword::Sword(std::string title, std::string description) :
	Weapon(title, description, 10, 2, 2, 10)
{
}

Sword::~Sword()
{
}
