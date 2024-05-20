#pragma once
#include "entity.h"


class Character : public Entity
{
public:
	Character();
	~Character();

public:
	virtual void tick();
};