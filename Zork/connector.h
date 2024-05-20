#pragma once

#include "entity.h"
#include "room.h"

class Connector : public Entity
{
public:
	Connector();

public:
	void tick();

public:
	//const Room* target;
};