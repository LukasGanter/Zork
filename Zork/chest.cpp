#include "chest.h"
#include <iostream>

Chest::Chest(const std::string& title, const std::string& description, const ValueTokens token, Item* stored_item, bool is_locked, const ValueTokens code) :
	Storage(title, description, token, stored_item), is_locked(is_locked), code(code)
{
}

Chest::~Chest()
{
}

void Chest::print_contents()
{
	if (is_locked) {
		std::cout << "This chest is locked. You need a 5 digit number code to open it!";
	}
	else {
		Storage::print_contents();
	}
}

bool Chest::lock(const ValueTokens code)
{
	if (this->code == code) {
		std::cout << "You enter the code into the old, metal lock. With a loud click it closes, locking the contents securely.\n";
		is_locked = true;
		return true;
	}
	else {
		//std::cout << "You enter the code into the old, metal lock. But the shackle does not move into position. The code must be wrong!\n";
		return false;
	}
}

bool Chest::unlock(const ValueTokens code)
{
	if (this->code == code) {
		std::cout << "You enter the code into the old, metal lock. With a loud click it opens and the flap falls away.\n";
		is_locked = false;
		return true;
	}
	else {
		//std::cout << "You enter the code into the old, metal lock. But the shackle does not move. The code must be wrong!\n";
		return false;
	}
}

bool Chest::take_item(Player* player)
{
	if (is_locked) {
		std::cout << "This chest is locked. Unlock it first using the passcode!\n";
		return false;
	}
	else {
		return Storage::take_item(player);
	}
}

bool Chest::drop_item(Item* item)
{
	if (is_locked) {
		std::cout << "This chest is locked. Unlock it first using the passcode!\n";
		return false;
	}
	else {
		return Storage::drop_item(item);
	}
}
