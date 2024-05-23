#include "medaillon.h"

Medaillon::Medaillon(const std::string& title, const std::string& description, const ValueTokens token, const std::string& story) :
	Collectible(title, description, token, story)
{
}

Medaillon::~Medaillon()
{
}