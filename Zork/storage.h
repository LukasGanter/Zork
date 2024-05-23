#pragma once

#include "item.h"

class Player;

class Storage : public Item
{
public:
	Storage(const std::string& title, const std::string& description, const ValueTokens token, Item* stored_item);
	~Storage();

	/*
	Prints an overview over the items in this storage.
	May be overridden by sub classes to restrict access to the contents of the storage
	*/
	virtual void print_contents();

	/*
	Tries to take the item from the storage

	Input "player":	the player who wants to take the item

	Output:			If the item was added to the inventory
	*/
	virtual bool take_item(Player* player, const ValueTokens token);

	/*
	Tries to place an item in the storage

	Input "item":	the item to be placed in the storage

	Output:			If the item was added to the storage
	*/
	virtual bool drop_item(Item* item);

protected:

	Item* stored_item;
};