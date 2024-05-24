#pragma once

#include "weapon.h"

class Stick : public Weapon
{
public:
	Stick(const std::string& title, const std::string& description, const ValueTokens token, const int attack_points, const int destruction_points, const int defence_points, const int durability);
	~Stick();

public:

	/*
	Called when the player attacks an npc. Does not modify the npc object, it is only used for gathering information regarding resistance against attacks
	The stats of the weapon itself are modified depending on the resistance of the enemy
	Function not in use in this version of the game

	Input "attacked_npc":	The npc which is getting attacked

	Return:					the number of damage the npc should receive
	*/
	int attack_enemy(const NPC* attacked_npc) override;

	/*
	Called when the player defends against an npc. Does not modify the npc object, it is only used for gathering information regarding attack strength
	The stats of the weapon itself are modified depending on the attack
	Function not in use in this version of the game

	Input "attacking_npc":	The npc which is attacking

	Return:					the number of damage the player should receive
	*/
	int defend_attack(const NPC* attacking_npc) override;

	/*
	Called when the player hits an obstacle.
	The stats of the weapon itself are modified depending on the resistance of the obstacle
	Function not in use in this version of the game

	Input "resistance":	The resistance of the obstacle

	Return:				the number of damage the obstacle should receive
	*/
	int destroy_obstacle(const int resistance) override;
};