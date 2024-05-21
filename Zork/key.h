#pragma once
#include "collectible.h"

class Key : public Collectible
{
public:
	Key(const std::string& id, const std::string& title, const std::string& description);
	~Key();
};