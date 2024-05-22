#include "key.h"

Key::Key(const std::string& title, const std::string& description, const std::string& story) :
	Collectible(title, description, story)
{
}

Key::~Key()
{
}
