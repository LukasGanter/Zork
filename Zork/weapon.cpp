#include "weapon.h"

Weapon::Weapon(std::string title, std::string description, int attack_points, int destruction_points, int defence_points, int durability) :
	Item(title, description), attack_points(attack_points), destruction_points(destruction_points), defence_points(defence_points), durability(durability)
{
}

Weapon::~Weapon()
{
}
