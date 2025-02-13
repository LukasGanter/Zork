#pragma once

#include "collectible.h"

class LetterFragment : public Collectible
{
public:
	LetterFragment(const std::string& title, const std::string& description, const ValueTokens token);
	~LetterFragment();
};