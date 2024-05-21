#pragma once

#include "collectible.h"

class LetterFragment : public Collectible
{
public:
	LetterFragment(const std::string& id, const std::string& title, const std::string& description);
	~LetterFragment();
};