#include "collectible.h"

Collectible::Collectible(const std::string& id, const std::string& title, const std::string& description) :
	Item(id, title, description)
{
}

Collectible::~Collectible()
{
}
