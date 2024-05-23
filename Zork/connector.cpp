#include "connector.h"
#include "room.h"
#include <iostream>

Connector::Connector(const std::string& title, const std::string& description, const ValueTokens token, Storyline* story, const ValueTokens exit_direction, bool is_locked, const ValueTokens suitable_key, int door_blocked_by, int block_resistance) :
	Entity(title, description), token(token), story(story), target(target), exit_direction(exit_direction), is_locked(is_locked), suitable_key(suitable_key), door_blocked_by(door_blocked_by), player(nullptr), block_resistance(block_resistance)
{
	
}

Connector::~Connector()
{
	// Delete all stored pointers 

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

bool Connector::take_connector(const ValueTokens direction, Player* player)
{
	// Check if the direction is valid
	if (exit_direction == direction) {
		if (is_locked) {
			std::cout << "This door blocking this way is locked! Do you have a suitable key?\n";
		} else if (door_blocked_by > 0) {
			std::cout << "This way is blocked by a bunch of debries! Try to clear it using special tools\n";
		}
		this->player = player;
		return true;
	}
	return false;
}

bool Connector::lock(const ValueTokens key)
{
	if (suitable_key == key) {
		if (is_locked) {
			std::cout << "The door is already locked!\n";
			return true;
		}
		else {
			is_locked = true;
			std::cout << "Door locked!\n";
			return true;
		}
	}
	return false;
}

bool Connector::unlock(const ValueTokens key)
{
	if (suitable_key == key) {
		if (!is_locked) {
			std::cout << "The door is already unlocked!\n";
			return true;
		}
		else {
			is_locked = false;
			std::cout << "Door unlocked!\n";
			return true;
		}
	}
	return false;
}

bool Connector::unblock(Weapon* weapon_to_use)
{
	if (door_blocked_by <= 0) {
		std::cout << "There is no obstacle to destroy. Come on, just walk through!\n";
		return true;
	} else if (weapon_to_use == nullptr) {
		std::cout << "You have no tool equiped to destroy the obstacle. Your fists will break trying to break that!\n";
		return false;
	}
	door_blocked_by -= weapon_to_use->destroy_obstacle(block_resistance);
	if (door_blocked_by <= 0) {
		std::cout << "You removed the obstacle. The way is free!\n";
		return true;
	}
	else {
		std::cout << "Those old wooden planks are for sure sturdier than they look. You will need to hit them again!\n";
		return false;
	}
	
}
