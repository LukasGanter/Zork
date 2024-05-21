#include "weapon.h"

Weapon::Weapon(const std::string& id, const std::string& title, const std::string& description, const int attack_points, const int destruction_points, const int defence_points, const int durability) :
	Item(id, title, description), attack_points(attack_points), destruction_points(destruction_points), defence_points(defence_points), durability(durability)
{
}

Weapon::~Weapon()
{
}

int Weapon::attack_enemy(const NPC* attacked_npc)
{
	return 0;
}

int Weapon::destroy_obstacle(const int resistance)
{
	return 0;
}
