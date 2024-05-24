#pragma once
#include "entity.h"


class Character : public Entity
{
public:
	Character(const std::string& title, const std::string& description);
	~Character();

public:

	// Game tick
	virtual void tick();

public:

	bool is_alive;
};