#pragma once

#include <vector>
#include "connector.h"
#include "character.h"
#include "weapon.h"
#include "collectible.h"
#include "tokenizer.h"
#include "npc.h"
#include "player.h"

class Room : public Entity
{
public:
	Room(const std::string& title, const std::string& description, Player* player, std::initializer_list<Connector*> connectors, std::initializer_list<NPC*> npcs, std::initializer_list<Item*> items);
	~Room();

public:
	/*
	Updates the room using tokens parsed from the player input

	Input "order_token":	the order the player gives
	Input "value_token":	the value the player adds to the order
	*/
	void update_by_token(std::vector<OrderTokens>& order_tokens, std::vector<ValueTokens>& value_tokens);

	// World tick
	void tick();

	/*
	Player joins the room 

	Input "player":	the player to be from now on present inside this room
	*/
	void join_room(Player* player);

	/*
	Adds the specified item to the lists inside this room

	Input "item":	the item to be added to the room
	*/
	void drop_item(Item* item);

private:

	void look_around();

public:

	Player* player;

	std::vector<Connector*> connectors;
	std::vector<NPC*> npcs;
	std::vector<Item*> items;
};

