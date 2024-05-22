#pragma once

#include "weapon.h"

class Sword : public Weapon
{
public:
	Sword(const std::string& title, const std::string& description, const int attack_points, const int destruction_points, const int defence_points, const int durability);
	~Sword();

public:

	int attack_enemy(const NPC* attacked_npc) override;

	int defend_attack(const NPC* attacking_npc) override;

	int destroy_obstacle(const int resistance) override;
};