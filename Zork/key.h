#pragma once
#include "collectible.h"

class Key : public Collectible
{
public:
	Key(const std::string& title, const std::string& description, const ValueTokens token, const std::string& content);
	~Key();
};