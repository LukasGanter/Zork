#pragma once

#include "collectible.h"

class Medallion : public Collectible
{
public:
	Medallion(const std::string& title, const std::string& description, const ValueTokens token, const std::string& content);
	~Medallion();
};