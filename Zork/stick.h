#pragma once

#include "weapon.h"

class Stick : public Weapon
{
public:
	Stick(std::string title, std::string description);
	~Stick();
};