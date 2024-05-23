#include "medallion.h"

Medallion::Medallion(const std::string& title, const std::string& description, const ValueTokens token, const std::string& story) :
	Collectible(title, description, token, story)
{
}

Medallion::~Medallion()
{
}