#pragma once

#include "entity.h"
#include "tokenizer.h"
#include "storyline.h"
#include "player.h"

class Room;

class Connector : public Entity
{
public:
	Connector(const std::string& title, const std::string& description, const ValueTokens token, Storyline* story, const ValueTokens exit_direction, bool is_locked, const ValueTokens suitable_key, int door_blocked_by, int block_resistance);
	~Connector();

	/*
	Sets the value of the target room for this connector
	*/
	void init_target(Room* target);
public:
	/*
	World tick
	*/
	void tick();

	/*
	Called when the player wants to use this connector to switch to the next room

	Input "direction":	indicated in which the player wants to leave the room he is currently in
	Input "player":		player object who wants to take the connector

	Output:				Whether the player switched rooms or not
	*/
	bool take_connector(const ValueTokens direction, Player* player);

	/*
	Tries to lock the given connector with the provided key

	Input "key":	the key value which the user entered. 

	Output:			Whether the door was successfully locked
	*/
	bool lock(const ValueTokens key);

	/*
	Tries to unlock the given connector with the provided key

	Input "key":	the key value which the user entered

	Output:			Whether the door was successfully unlocked
	*/
	bool unlock(const ValueTokens key);

	/*
	Tries to unblock the given connector

	Input "weapon_to_use":	the weapon which will be used 

	Output:					Whether the door was successfully unblocked
	*/
	bool unblock(Weapon* weapon_to_use);
private:

	Storyline* story;
	Player* player;

	Room* target;
	bool is_locked;
	const ValueTokens suitable_key;
	int door_blocked_by; // If value is <= 0 then the exit is not blocked
	int block_resistance;

public:

	const ValueTokens token;
	const ValueTokens exit_direction;
};