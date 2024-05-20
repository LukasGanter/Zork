#pragma once
#include "item.h"

class Weapon : public Item
{
public:
	Weapon();
	~Weapon();

protected:
	int attack_points;
	int destruction_points;
	int defence_points;

	int durability;
};