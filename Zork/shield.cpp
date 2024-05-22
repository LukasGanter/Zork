#include "shield.h"
#include <iostream>

Shield::Shield(const std::string& title, const std::string& description, const int attack_points, const int destruction_points, const int defence_points, const int durability) :
	Weapon(title, description, attack_points, destruction_points, defence_points, durability)
{
}

Shield::~Shield()
{
}

int Shield::attack_enemy(const NPC* attacked_npc)
{
	std::cout << "You decide to attack " << attacked_npc->title << " using your sturdy shield.\n";
	print_stats();

	const int dealt_damage = attack_points - attacked_npc->resistance;

	attack_points -= 1;
	attack_points = std::max(0, attack_points);
	destruction_points -= 1;
	destruction_points = std::max(0, destruction_points);

	durability -= 2; // Currently not in use

	std::cout << "The costs are high, but you dealt " << dealt_damage << " damage!\n";
	print_stats();

	return dealt_damage;
}

int Shield::defend_attack(const NPC* attacking_npc)
{
	std::cout << "You defend yourself using your sturdy shield.\n";
	print_stats();

	const int received_damage = attacking_npc->attack_dmg - defence_points;

	defence_points -= 1;
	defence_points = std::max(0, attack_points);

	durability -= 2; // Currently not in use

	std::cout << "The costs are high, but you managed to deflect " << defence_points << " damage! Still, that hurt: " << received_damage << ".\n";
	print_stats();

	return received_damage;
}

int Shield::destroy_obstacle(const int resistance)
{
	std::cout << "You decide to destroy the obstacle using your sturdy shield.\n";
	print_stats();

	const int dealt_damage = destruction_points / resistance;

	attack_points -= resistance * 2;
	attack_points = std::max(0, attack_points);
	destruction_points -= resistance * 2;
	destruction_points = std::max(0, destruction_points);

	durability -= resistance * 2; // Currently not in use

	std::cout << "The costs are high, but you dealt " << dealt_damage << " damage!\n";
	print_stats();

	return dealt_damage;
}
