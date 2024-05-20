#pragma once

#include "weapon.h"

class Sword : public Weapon
{
public:
	Sword(std::string title, std::string description);
	~Sword();
};