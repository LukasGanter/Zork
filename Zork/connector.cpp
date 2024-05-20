#include "connector.h"
#include "room.h"
#include <iostream>

Connector::Connector(std::string title, std::string description, Storyline* story, Room* target, ValueTokens exit_direction, bool isLocked, ValueTokens suitable_key, int doorBlockedBy) :
	Entity(title, description), story(story), target(target), exit_direction(exit_direction), isLocked(isLocked), suitable_key(suitable_key), doorBlockedBy(doorBlockedBy), player(nullptr)
{
	//this->target = target;
}

Connector::~Connector()
{
	delete player;
	delete target;
	delete story;
	player = nullptr;
	target = nullptr;
	story = nullptr;
}

void Connector::tick()
{
	if (player != nullptr) {
		if (story->tick()) {
			// Story finished, switching to next room
			target->joinRoom(player);
			player = nullptr;
		}
	}
}

bool Connector::takeConnector(const ValueTokens& direction, Player* player)
{
	// Check if the direction is valid
	if (exit_direction == direction) {
		if (isLocked) {
			std::cout << "This door blocking this way is locked! Do you have a suitable key?\n";
		} else if (doorBlockedBy > 0) {
			std::cout << "This way is blocked by a bunch of debries! Try to clear it using special tools\n";
		}
		this->player = player;
		return true;
	}
	return false;
}
