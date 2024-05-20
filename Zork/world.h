#pragma once
#include "entity.h"
#include <vector>
#include "room.h"

class World : public Entity
{
public:
	World(std::string title, std::string description);
	~World();

public:
	void onPlayerInput(const std::string& input);
	void tick();

private:

	std::vector<Room*> rooms;
};