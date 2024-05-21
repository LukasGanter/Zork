#pragma once

#include "weapon.h"

class Stick : public Weapon
{
public:
	Stick(const std::string& id, const std::string& title, const std::string& description, const int attack_points, const int destruction_points, const int defence_points, const int durability);
	~Stick();

public:

	int attack_enemy(const NPC* attacked_npc) override;

	int destroy_obstacle(const int resistance) override;
};