#pragma once
#include "item.h"

class Collectible : public Item
{
public:
	Collectible(const std::string& id, const std::string& title, const std::string& description);
	~Collectible();
};