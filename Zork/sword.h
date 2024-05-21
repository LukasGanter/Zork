#pragma once

#include "weapon.h"

class Sword : public Weapon
{
public:
	Sword(const std::string& id, const std::string& title, const std::string& description, const int attack_points, const int destruction_points, const int defence_points, const int durability);
	~Sword();
};