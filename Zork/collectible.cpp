#include "collectible.h"
#include <iostream>

Collectible::Collectible(const std::string& title, const std::string& description, const ValueTokens token, const std::string& story) :
	Item(title, description, true, token), content(story)
{
}

Collectible::~Collectible()
{
}

void Collectible::read_story()
{
	std::cout << content << "\n";
}
