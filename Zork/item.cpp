#include "item.h"

Item::Item(const std::string& title, const std::string& description, const bool is_takable, const ValueTokens token) :
	Entity(title, description), is_takable(is_takable), token(token)
{
}

Item::~Item()
{
}
