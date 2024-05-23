#include "key.h"

Key::Key(const std::string& title, const std::string& description, const ValueTokens token, const std::string& story) :
	Collectible(title, description, token, story)
{

}

Key::~Key()
{
}
