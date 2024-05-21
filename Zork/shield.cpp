#include "shield.h"

Shield::Shield(const std::string& id, const std::string& title, const std::string& description, const int attack_points, const int destruction_points, const int defence_points, const int durability) :
	Weapon(id, title, description, attack_points, destruction_points, defence_points, durability)
{
}

Shield::~Shield()
{
}
