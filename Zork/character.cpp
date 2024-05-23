#include "character.h"

Character::Character(const std::string& title, const std::string& description) :
	Entity(title, description), is_alive(true)
{
}

Character::~Character()
{
}

void Character::tick()
{
}
