#pragma once
#include "item.h"
#include "npc.h"

class Weapon : public Item
{
public:
	Weapon(const std::string& title, const std::string& description, const ValueTokens token, const int attack_points, const int destruction_points, const int defence_points, const int durability);
	~Weapon();

	/*
	Attack the given enemy with this weapon. 
	Will affect the stats of the weapon.

	Input "attacked_npc":	the npc which should be attacked. Will not be modified

	Output:					The damage number which the player dealt with this attack
	*/
	virtual int attack_enemy(const NPC* attacked_npc) = 0;

	/*
	Defends from an attack
	Will affect the stats of the weapon.

	Input "attacking_npc":	the npc which attacks. Will not be modified

	Output:					The damage number which the player received
	*/
	virtual int defend_attack(const NPC* attacking_npc) = 0;

	/*
	Attack the given obstacle with this weapon.
	Will affect the stats of the weapon.

	Input "resistance":		the "hardness" of the object. A larger number will affect the effectivness of the weapon

	Output:					The damage number which the player dealt with this attack
	*/
	virtual int destroy_obstacle(const int resistance) = 0;

protected:

	// Prints the current statistics of the weapon
	void print_stats();

protected:

	int attack_points;
	int destruction_points;
	int defence_points;

	int durability; // Currently not in use
};