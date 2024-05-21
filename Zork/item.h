#pragma once

#include "entity.h"

class Item : public Entity
{
public:
	Item(const std::string& id, const std::string& title, const std::string& description);
	~Item();
};
