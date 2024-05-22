#include "entity.h"
#include <iostream>

Entity::Entity(const std::string& title, const std::string& description) : title(title), description(description)
{
}

Entity::~Entity()
{
}

const void Entity::print_information()
{
	std::cout << title << ": " << description << "\n";
}
