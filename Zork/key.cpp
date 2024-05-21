#include "key.h"

Key::Key(const std::string& id, const std::string& title, const std::string& description) :
	Collectible(id, title, description)
{
}

Key::~Key()
{
}
