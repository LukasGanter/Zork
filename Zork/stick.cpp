#include "stick.h"

Stick::Stick(const std::string& id, const std::string& title, const std::string& description, const int attack_points, const int destruction_points, const int defence_points, const int durability) :
	Weapon(id, title, description, attack_points, destruction_points, defence_points, durability)
{
}

Stick::~Stick()
{
}

int Stick::attack_enemy(const NPC* attacked_npc)
{
	return 0;
}

int Stick::destroy_obstacle(const int resistance)
{
	return 0;
}
