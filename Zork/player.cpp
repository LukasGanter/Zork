#include "player.h"
#include "room.h"
#include <iostream>

Player::Player(const std::string& title, const std::string& description) :
	Character(title, description), equiped_weapon(nullptr)
{
}

Player::~Player()
{
	delete equiped_weapon;
	equiped_weapon = nullptr;
}

void Player::tick()
{
}

bool Player::equip_weapon(const ValueTokens weapon)
{
	if (equiped_weapon != nullptr) {
		std::cout << "Deep in thoughts you try to get a new weapon out of your bag. Then you remember. You are already handling "<< equiped_weapon->title << "\n";
		return false;
	}

	int item_to_equip = -1;
	for (size_t i = 0; i < inventory.size(); i++) {
		if (inventory[i]->token == weapon) {
			item_to_equip = i;
			break;
		}
	}

	if (item_to_equip != -1) {
		std::cout << "You take " << item_to_equip << " out of your bag and hold it in both hands, slightly smiling. You are ready!\n";
		equiped_weapon = static_cast<Weapon*>(inventory[item_to_equip]);
		inventory.erase(inventory.begin() + item_to_equip);
		return true;
	}
	else {
		std::cout << "You don´t possess an item with that name!\n";
		return false;
	}
}

bool Player::unequip_weapon(Room* room)
{
	if (equiped_weapon != nullptr) {
		if (inventory.size() < max_inventory_size) {
			std::cout << "You remove your " << equiped_weapon->title << " from your arms and put it in your bag.\n";
			inventory.push_back(equiped_weapon);
			equiped_weapon = nullptr;
		}
		else {
			std::cout << "Your bag is too heavy. Completely out of strength your drop " << equiped_weapon->title << "on the floor.\n";
		}
		return true;
	}
	else {
		std::cout << "You search everywhere. In both hands, on your arms, under your armpits, even at your feet. You can not find a equipped weapon. You give up and continue to observe the room.\n";
		return false;
	}
}

bool Player::take_item(Item* item, const ValueTokens token)
{
	if (!item->is_takable) {
		std::cout <<  item->title << " is tot heavy to pick up.\n";
		return false;
	}
	else if (item->token != token) {
		return false;
	}
	else if (inventory.size() < max_inventory_size) {
		std::cout << "You take the " << item->title << " and put it in your bag.\n";
		inventory.push_back(item);
		return true;
	}
	else {
		std::cout << "Your bag is too heavy. Remove some weight first before picking new item up.\n";
		return false;
	}
}

bool Player::drop_item(Room* room, const ValueTokens item)
{
	int itemToRemove = -1;
	for (size_t i = 0; i < inventory.size(); i++) {
		if (inventory[i]->token == item) {
			itemToRemove = i;
			break;
		}
	}

	if (itemToRemove != -1) {
		std::cout << "You drop the item in the middle of the room\n";
		room->drop_item(inventory[itemToRemove]);
		inventory.erase(inventory.begin() + itemToRemove);
		return true;
	}
	else {
		std::cout << "You don´t possess an item with that name!\n";
		return false;
	}
}

bool Player::drop_item_into_storage(Storage* storage, const ValueTokens item_token)
{
	int itemToRemove = -1;
	for (size_t i = 0; i < inventory.size(); i++) {
		if (inventory[i]->token == item_token) {
			itemToRemove = i;
			break;
		}
	}

	if (itemToRemove != -1) {

		if (storage->drop_item(inventory[itemToRemove])) {
			inventory.erase(inventory.begin() + itemToRemove);
			return true;
		}
		else {
			return false;
		}
	}
	else {
		std::cout << "You don´t possess such an item!\n";
		return false;
	}
}

void Player::drop_inventory(Room* room)
{
	std::cout << "You drop everything you have in every pocket and cause a mess inside the room.\n";
	for (Item* item : inventory) {
		room->drop_item(item);
	}
	inventory.clear();
}

void Player::search_inventory()
{
	if (inventory.empty()) {
		std::cout << "There is nothing inside your inventory!\n";
	}
	else {
		std::cout << "You have some items inside your inventory. Let´s see what it is.\n";
		for (Item* item : inventory) {
			item->print_information();
		}
	}
	
}

void Player::read(const ValueTokens token)
{
	for (Item* item : inventory) {
		if (item->token == token) {
			if (static_cast<Collectible*>(item)) {
				static_cast<Collectible*>(item)->read_story();
			}
			else {
				std::cout << "This item does not have a story.\n";
			}
			return;
		}
	}
	std::cout << "This item does not exist in your inventory\n";
}

bool Player::has_medallion()
{
	for (Item* item : inventory) {
		if (item->token == ValueTokens::MEDALLION_WISEDOM) {
			return true;
		}
	}
	return false;
}

bool Player::get_keys_in_inventory(std::vector<Key*>& keys)
{
	for (Item* item : inventory) {
		if (static_cast<Key*>(item)) {
			keys.push_back(static_cast<Key*>(item));
		}
	}
	return !keys.empty();
}

void Player::remember_key(const ValueTokens new_key)
{
	if (new_key == ValueTokens::PASSCODE_TREASURE_CHEST) {
		for (Item* item : inventory) {
			if (item->token == ValueTokens::PASSCODE_TREASURE_CHEST) {
				std::cout << "You already remembered that passcode.\n";
				return;
			}
		}
		inventory.push_back(new Key("Passcode", "A number sequence, might be relevant later on", new_key, ""));
		std::cout << "You write the passcode onto a piece of old fabric and put it in your backpack. You never know when you need it.\n";
	}
	else {
		std::cout << "You realize that this code is not relevant for the game.\n";
	}
	
}

