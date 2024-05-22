#pragma once

#include "entity.h"
#include <vector>
#include "room.h"

class World : public Entity
{
public:
	World(const std::string& title, const std::string& description);
	~World();

public:

	/*
	Called if the user entered something into the console and pressed enter

	Input "input":	the string the player entered
	*/
	void on_player_input(const std::string& input);

	// Game tick
	void tick();

private:

	std::vector<Room*> rooms;
};