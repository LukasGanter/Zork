#pragma once

#include "entity.h"
#include "tokenizer.h"

class Item : public Entity
{
public:
	Item(const std::string& title, const std::string& description, const bool is_takable, const ValueTokens token);
	~Item();

public:

	const bool is_takable;
	const ValueTokens token;
};
