#include "collectible.h"
#include <iostream>

Collectible::Collectible(const std::string& title, const std::string& description, const std::string& story) :
	Item(title, description), story(story)
{
}

Collectible::~Collectible()
{
}

void Collectible::read_story()
{
	std::cout << story << "\n";
}
