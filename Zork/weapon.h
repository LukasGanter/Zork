#pragma once
#include "item.h"

class Weapon : public Item
{
public:
	Weapon(std::string title, std::string description, int attack_points, int destruction_points, int defence_points, int durability);
	~Weapon();

protected:
	int attack_points = 0;
	int destruction_points = 0;
	int defence_points = 0;

	int durability = 0;
};