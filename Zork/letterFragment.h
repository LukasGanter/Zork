#pragma once

#include "collectible.h"

class LetterFragment : public Collectible
{
public:
	LetterFragment(std::string title, std::string description);
	~LetterFragment();
};