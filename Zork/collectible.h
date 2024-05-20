#pragma once
#include "item.h"

class Collectible : public Item
{
public:
	Collectible(std::string title, std::string description);
	~Collectible();
};