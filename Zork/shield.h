#pragma once

#include "weapon.h"

class Shield : public Weapon
{
public:
	Shield(std::string title, std::string description);
	~Shield();
};