#pragma once

#include "storage.h"
#include "tokenizer.h"

class Chest : public Storage
{
public:
	Chest(const std::string& title, const std::string& description, const ValueTokens token, Item* stored_item, bool is_locked, const ValueTokens code);
	~Chest();

	/*
	Prints an overview over the items in this storage if the chest is unlocked
	*/
	void print_contents() override;

	/*
	Tries to lock the chest with the provided code

	Input "code":		the code for the chests lock

	Output:				Whether the chest was successfully locked
	*/
	bool lock(const ValueTokens code);

	/*
	Tries to unlock the chest with the provided code

	Input "code":		the code for the chests unlock

	Output:				Whether the chest was successfully unlocked
	*/
	bool unlock(const ValueTokens code);

	/*
	Tries to take the item from the storage

	Input "player":	the player who wants to take the item

	Output:			If the item was added to the inventory
	*/
	bool take_item(Player* player, const ValueTokens token) override;

	/*
	Tries to place an item in the storage 

	Input "item":	the item to be placed in the storage

	Output:			If the item was added to the storage
	*/
	bool drop_item(Item* item) override;

protected:

	bool is_locked;
	const ValueTokens code;
};