#include "key.h"

Key::Key(const std::string& title, const std::string& description, const ValueTokens token) :
	Collectible(title, description, token)
{

}

Key::~Key()
{
}
