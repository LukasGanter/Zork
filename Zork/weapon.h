#pragma once
#include "item.h"
#include "npc.h"

class Weapon : public Item
{
public:
	Weapon(const std::string& id, const std::string& title, const std::string& description, const int attack_points, const int destruction_points, const int defence_points, const int durability);
	~Weapon();

	/*
	Attack the given enemy with this weapon. 
	Will affect the stats of the weapon.

	Input "attacked_npc":	the npc which should be attacked. Will not be modified

	Output:					The damage number which the player dealt with this attack
	*/
	virtual int attack_enemy(const NPC* attacked_npc);

	/*
	Attack the given obstacle with this weapon.
	Will affect the stats of the weapon.

	Input "resistance":		the "hardness" of the object. A larger number will affect the effectivness of the weapon

	Output:					The damage number which the player dealt with this attack
	*/
	virtual int destroy_obstacle(const int resistance);

protected:
	int attack_points;
	int destruction_points;
	int defence_points;

	int durability;
};