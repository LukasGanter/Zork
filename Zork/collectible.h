#pragma once
#include "item.h"

class Collectible : public Item
{
public:
	Collectible(const std::string& title, const std::string& description, const ValueTokens token);
	~Collectible();

};