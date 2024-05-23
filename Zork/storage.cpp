#include "storage.h"
#include <iostream>
#include "player.h"

Storage::Storage(const std::string& title, const std::string& description, const ValueTokens token, Item* stored_item) :
	Item(title, description, false, token), stored_item(stored_item)
{
}

Storage::~Storage()
{
	delete stored_item;
	stored_item = nullptr;
}

void Storage::print_contents()
{
	if (stored_item == nullptr) {
		std::cout << "This storage is empty.\n";
	}
	else {
		std::cout << "You open the storage and find inside:\n";
		stored_item->print_information();
	}
}

bool Storage::take_item(Player* player)
{
	if (stored_item == nullptr) {
		std::cout << "This storage is empty.\n";
		return false;
	}
	else {
		// If the player can take the item to the inventory continue
		if (player->take_item(stored_item, stored_item->token)) {
			stored_item = nullptr;
			return true;
		} else {
			return false;
		}
	}
}

bool Storage::drop_item(Item* item)
{
	if (stored_item == nullptr) {
		std::cout << "You drop the item " << item->title << " into the storage.\n";
		stored_item = item;
		return true;
	}
	else {
		std::cout << "The storage is already full. It contains " << stored_item->title << "\n";
	}
}
