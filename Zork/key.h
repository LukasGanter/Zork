#pragma once
#include "collectible.h"

class Key : public Collectible
{
public:
	Key(std::string title, std::string description);
	~Key();
};