#include "player.h"

Player::Player(const std::string& id, const std::string& title, const std::string& description) :
	Character(id, title, description)
{
	equiped_weapon = nullptr;
	has_backpack = false;

}

Player::~Player()
{
	equiped_weapon = nullptr;
}

void Player::tick()
{
}

bool Player::equip_weapon(Weapon* weapon)
{
	return false;
}

bool Player::unequip_weapon()
{
	return false;
}

bool Player::take_item(Item* item)
{
	return false;
}

bool Player::drop_inventory()
{
	return false;
}

void Player::search_inventory()
{
	for (Item* item : inventory) {
		item->printInformation();
	}
}

