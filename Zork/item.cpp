#include "item.h"

Item::Item(const std::string& id, const std::string& title, const std::string& description) :
	Entity(id, title, description)
{
}

Item::~Item()
{
}
