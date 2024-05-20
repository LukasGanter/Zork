#pragma once

#include "entity.h"
#include "room.h"

class Connector : public Entity
{
public:
	Connector(std::string title, std::string description);

public:
	void tick();

public:
	//const Room* target;
};