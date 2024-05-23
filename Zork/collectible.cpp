#include "collectible.h"
#include <iostream>

Collectible::Collectible(const std::string& title, const std::string& description, const ValueTokens token) :
	Item(title, description, true, token)
{
}

Collectible::~Collectible()
{
}
