#pragma once
#include "entity.h"


class Character : public Entity
{
public:
	Character(std::string title, std::string description);
	~Character();

public:
	virtual void tick();
};