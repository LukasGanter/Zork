#include "character.h"

Character::Character(const std::string& id, const std::string& title, const std::string& description) :
	Entity(id, title, description)
{
}

Character::~Character()
{
}

void Character::tick()
{
}
