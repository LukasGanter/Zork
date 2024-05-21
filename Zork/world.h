#pragma once

#include "entity.h"
#include <vector>
#include "room.h"

class World : public Entity
{
public:
	World(const std::string& id, const std::string& title, const std::string& description);
	~World();

public:
	void on_player_input(const std::string& input);
	void tick();

private:

	std::vector<Room*> rooms;
};