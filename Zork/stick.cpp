#include "stick.h"
#include <iostream>

Stick::Stick(const std::string& id, const std::string& title, const std::string& description, const int attack_points, const int destruction_points, const int defence_points, const int durability) :
	Weapon(id, title, description, attack_points, destruction_points, defence_points, durability)
{
}

Stick::~Stick()
{
}

int Stick::attack_enemy(const NPC* attacked_npc)
{
	std::cout << "You decide to attack " << attacked_npc->title << " using your mighty stick.\n";
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

int Stick::defend_attack(const NPC* attacking_npc)
{
	std::cout << "You defend yourself using your mighty stick.\n";
	print_stats();

	const int received_damage = attacking_npc->attack_dmg - defence_points;

	defence_points -= 1;
	defence_points = std::max(0, attack_points);

	durability -= 2; // Currently not in use

	std::cout << "The costs are high, but you managed to deflect " << defence_points << " damage! Still, that hurt: " << received_damage << ".\n";
	print_stats();

	return received_damage;
}

int Stick::destroy_obstacle(const int resistance)
{
	std::cout << "You decide to destroy the obstacle using your mighty stick.\n";
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
