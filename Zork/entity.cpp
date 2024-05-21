#include "entity.h"
#include <iostream>

Entity::Entity(const std::string& id, const std::string& title, const std::string& description) : id(id), title(title), description(description)
{
}

Entity::~Entity()
{
}

const void Entity::printInformation()
{
	std::cout << title << ": " << description;
}
