#pragma once

#include "entity.h"
#include "tokenizer.h"
#include "storyline.h"
#include "player.h"

class Room;

class Connector : public Entity
{
public:
	Connector(std::string title, std::string description, Storyline* story, Room* target, ValueTokens exit_direction, bool isLocked, ValueTokens suitable_key, int doorBlockedBy);
	~Connector();

public:
	void tick();
	bool takeConnector(const ValueTokens& direction, Player* player);

private:

	Storyline* story;
	Player* player;

	Room* target;
	ValueTokens exit_direction;
	bool isLocked;
	ValueTokens suitable_key;
	int doorBlockedBy; // If value is 0 then the exit is not blocked
};