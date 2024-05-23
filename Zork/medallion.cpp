#include "medallion.h"

Medallion::Medallion(const std::string& title, const std::string& description, const ValueTokens token) :
	Collectible(title, description, token)
{
}

Medallion::~Medallion()
{
}