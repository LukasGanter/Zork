#pragma once
#include "item.h"

class Weapon : public Item
{
public:
	Weapon(const std::string& id, const std::string& title, const std::string& description, const int attack_points, const int destruction_points, const int defence_points, const int durability);
	~Weapon();

protected:
	int attack_points;
	int destruction_points;
	int defence_points;

	int durability;
};