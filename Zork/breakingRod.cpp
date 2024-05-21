#include "breakingRod.h"

BreakingRod::BreakingRod(const std::string& id, const std::string& title, const std::string& description, const int attack_points, const int destruction_points, const int defence_points, const int durability) :
	Weapon(id, title, description, attack_points, destruction_points, defence_points, durability)
{
}

BreakingRod::~BreakingRod()
{
}

int BreakingRod::attack_enemy(const NPC* attacked_npc)
{
	return 0;
}

int BreakingRod::destroy_obstacle(const int resistance)
{
	return 0;
}
