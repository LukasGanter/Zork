#pragma once

#include "character.h"
#include "weapon.h"
#include <vector>
#include "tokenizer.h"
#include "storage.h"
#include "key.h"

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
	Takes the specified item from the room or a storage and adds it to the inventory if the inventory is not full and if the token matches

	Input "item":	an item option
	Input "token":	the token which the user wants to take

	Output:			If the item was added to the inventory
	*/
	bool take_item(Item* item, const ValueTokens token);

	/*
	Drops the specified item into the room

	Input "room":		the room to drop the items into
	Input "item":		the token of the item 

	Output:				If the weapon was equipped
	*/
	bool drop_item(Room* room, const ValueTokens item);

	/*
	Tries to drop the equipped item into the specified storage container

	Input "storage":		the storage to drop the item into

	Output:					If the item existed in the inventory of the player and was dropped into the storage
	*/
	bool drop_item_into_storage(Storage* storage);

	/*
	Drops all items from the inventory and adds them to the room the player is currently in

	Input "room":	the room to drop the items into
	*/
	void drop_inventory(Room* room);

	/*
	Prints out an overview of all the items currently inside the inventory
	*/
	void search_inventory();

	/*
	Reads the story of a collectible if available

	Input "token":	The token of the item
	*/
	void read(const ValueTokens token);

	/*
	Utility function for checking if the player has the medallion in his inventory

	Return:		true if a medallion is in the players inventory, false otherwise
	*/
	bool has_medallion();

	/*
	Returns a list of all keys present in the players inventory

	Input "keys":	the output list for the keys

	Return:			whether any key was present
	*/
	bool get_keys_in_inventory(std::vector<Key*>& keys);

	/*
	Remembers a given number sequence as the key to a chest

	Input "new_key": The new key to remember
	*/
	void remember_key(const ValueTokens new_key);

private:

	Weapon* equiped_weapon;
	const size_t max_inventory_size = 70;
	std::vector<Item*> inventory;

};