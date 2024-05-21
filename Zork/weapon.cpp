#include "weapon.h"
#include <iostream>

Weapon::Weapon(const std::string& id, const std::string& title, const std::string& description, const int attack_points, const int destruction_points, const int defence_points, const int durability) :
	Item(id, title, description), attack_points(attack_points), destruction_points(destruction_points), defence_points(defence_points), durability(durability)
{
}

Weapon::~Weapon()
{
}

void Weapon::print_stats()
{
	std::cout << "Attack: " << attack_points << ", Destruction: " << destruction_points << ", Defence: " << defence_points << "\n"; //", Durability: " << durability << "\n"; (not currently in use)
}
