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

bool Player::equip_weapon(const ValueTokens weapon_type, const std::string& weapon_id)
{
	if (equiped_weapon != nullptr) {
		std::cout << "Deep in thoughts you try to get " << weapon_id << " out of your bag. Then you remember. You are already handling "<< equiped_weapon->title << "\n";
		return false;
	}

	int item_to_equip = -1;
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i]->title.compare(weapon_id) == 0) {
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
		std::cout << "You don´t possess an item with the name " << weapon_id << "!\n";
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

bool Player::take_item(Item* item)
{
	if (inventory.size() < max_inventory_size) {
		std::cout << "You take " << item->title << " from the floor and put it in your bag.\n";
		inventory.push_back(item);
		return true;
	}
	else {
		std::cout << "Your bag is too heavy. Remove some weight first before picking new item up.\n";
		return false;
	}
}

bool Player::drop_item(Room* room, const ValueTokens item_type, const std::string& item_id)
{
	int itemToRemove = -1;
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i]->title.compare(item_id) == 0) {
			itemToRemove = i;
			break;
		}
	}

	if (itemToRemove != -1) {
		std::cout << "You drop " << item_id << "in the middle of the room\n";
		room->drop_item(inventory[itemToRemove]);
		inventory.erase(inventory.begin() + itemToRemove);
		return true;
	}
	else {
		std::cout << "You don´t possess an item with the name " << item_id << "!\n";
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

