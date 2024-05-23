#pragma once

#include "character.h"
#include "weapon.h"
#include <vector>
#include "tokenizer.h"
#include "storage.h"

class Room;

class Player : public Character
{
public:
	Player(const std::string& title, const std::string& description);
	~Player();

public:
	void tick() override;

	/*
	Equips the specified weapon, if it is present inside the inventory and if no other weapon is currently equipped

	Input "weapon":		the token of the weapon

	Output:				If the weapon was equipped
	*/
	bool equip_weapon(const ValueTokens weapon);

	/*
	Unequipps the currently equipped weapon, if present. Adds it to the inventory or drops it if the inventory is full

	Input "room":			the room to drop the items into if the inventory is full

	Output:					If the weapon was unequipped
	*/
	bool unequip_weapon(Room* room);

	/*
	Takes the specified item from the room or a storage and adds it to the inventory if the inventory is not full

	Input "item":	the item to be taken

	Output:			If the item was added to the inventory
	*/
	bool take_item(Item* item);

	/*
	Drops the specified item into the room

	Input "room":		the room to drop the items into
	Input "item":		the token of the item 

	Output:				If the weapon was equipped
	*/
	bool drop_item(Room* room, const ValueTokens item);

	/*
	Tries to drop an item, specified by its token, into the specified storage container

	Input "storage":		the storage to drop the items into
	Input "item_token":		the token of the item to be dropped

	Output:					If the item existed in the inventory of the player and was dropped to the storage
	*/
	bool drop_item_into_storage(Storage* storage, const ValueTokens item_token);

	/*
	Drops all items from the inventory and adds them to the room the player is currently in

	Input "room":	the room to drop the items into
	*/
	void drop_inventory(Room* room);

	/*
	Prints out an overview of all the items currently inside the inventory
	*/
	void search_inventory();

private:

	Weapon* equiped_weapon;
	const size_t max_inventory_size = 7;
	std::vector<Item*> inventory;

};