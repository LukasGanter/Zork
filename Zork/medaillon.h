#pragma once

#include "collectible.h"

class Medaillon : public Collectible
{
public:
	Medaillon(std::string title, std::string description);
	~Medaillon();
};