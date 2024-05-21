#pragma once
#include "entity.h"


class Character : public Entity
{
public:
	Character(const std::string& id, const std::string& title, const std::string& description);
	~Character();

public:
	virtual void tick();
};