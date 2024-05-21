#include "connector.h"
#include "room.h"
#include <iostream>

Connector::Connector(const std::string& id, const std::string& title, const std::string& description, Storyline* story, Room* target, ValueTokens exit_direction, bool isLocked, ValueTokens suitable_key, int doorBlockedBy) :
	Entity(id, title, description), story(story), target(target), exit_direction(exit_direction), isLocked(isLocked), suitable_key(suitable_key), doorBlockedBy(doorBlockedBy), player(nullptr)
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

void Connector::init_target(Room* target)
{
	this->target = target;
}

void Connector::tick()
{
	if (player != nullptr) {
		if (story->tick()) {
			// Story finished, switching to next room
			target->join_room(player);
			player = nullptr;
		}
	}
}

bool Connector::take_connector(const ValueTokens& direction, Player* player)
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
