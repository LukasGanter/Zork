#include "entity.h"
#include <iostream>

Entity::Entity(std::string title, std::string description) : title(title), description(description)
{
}

Entity::~Entity()
{
}

const void Entity::printInformation()
{
	std::cout << title << ": " << description;
}
