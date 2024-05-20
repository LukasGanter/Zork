#pragma once

#include "entity.h"
#include "tokenizer.h"
#include "storyline.h"

class Room;

class Connector : public Entity
{
public:
	Connector(std::string title, std::string description);

public:
	void tick();

private:

	Storyline* story;

	Room* target;
	ValueTokens exit_direction;
	bool isLocked;
	ValueTokens suitable_key;
	int doorBlockedBy; // If value is 0 then the exit is not blocked
};