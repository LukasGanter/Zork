#pragma once
#include "entity.h"
#include <vector>
#include "room.h"

class World : public Entity
{
public:
	World();
	~World();

public:
	void tick();

public:
	std::vector<Room> rooms;
};