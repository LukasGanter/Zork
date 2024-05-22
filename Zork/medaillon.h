#pragma once

#include "collectible.h"

class Medaillon : public Collectible
{
public:
	Medaillon(const std::string& title, const std::string& description, const std::string& story);
	~Medaillon();
};