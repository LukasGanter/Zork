#pragma once

#include "weapon.h"

class Shield : public Weapon
{
public:
	Shield(const std::string& id, const std::string& title, const std::string& description, const int attack_points, const int destruction_points, const int defence_points, const int durability);
	~Shield();

public:

	int attack_enemy(const NPC* attacked_npc) override;

	int destroy_obstacle(const int resistance) override;
};