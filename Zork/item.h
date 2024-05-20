#pragma once

#include "entity.h"

class Item : public Entity
{
public:
	Item(std::string title, std::string description);
	~Item();
};
