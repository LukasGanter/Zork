#pragma once

#include "character.h"
#include "weapon.h"
#include <vector>
#include "tokenizer.h"

class Room;

class Player : public Character
{
public:
	Player(const std::string& id, const std::string& title, const std::string& description);
	~Player();

public:
	void tick() override;

	/*
	Equips the specified weapon, if it is present inside the inventory and if no other weapon is currently equipped

	Input "weapon_type":	the type of the weapon (sword, stick, ...)
	Input "weapon_id":		the unique id of the weapon

	Output:					If the weapon was equipped
	*/
	bool equip_weapon(const ValueTokens weapon_type, const std::string& weapon_id);

	/*
	Unequipps the currently equipped weapon, if present. Adds it to the inventory or drops it if the inventory is full

	Input "room":			the room to drop the items into if the inventory is full

	Output:					If the weapon was unequipped
	*/
	bool unequip_weapon(Room* room);

	/*
	Takes the specified item from the room and adds it to the inventory, if the inventory is not full

	Input "item":	the item to be taken

	Output:			If the item was added to the inventory
	*/
	bool take_item(Item* item);

	/*
	Equips the specified weapon, if it is present inside the inventory and if no other weapon is currently equipped

	Input "room":			the room to drop the items into
	Input "weapon_type":	the type of the weapon (sword, stick, ...)
	Input "weapon_id":		the unique id of the weapon

	Output:					If the weapon was equipped
	*/
	bool drop_item(Room* room, const ValueTokens item_type, const std::string& item_id);

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
	const int max_inventory_size = 7;
	std::vector<Item*> inventory;

};