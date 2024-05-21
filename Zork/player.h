#pragma once

#include "character.h"
#include "weapon.h"
#include <vector>

class Player : public Character
{
public:
	Player(const std::string& id, const std::string& title, const std::string& description);
	~Player();

public:
	void tick() override;

	bool equip_weapon(Weapon* weapon);
	bool unequip_weapon();
	bool take_item(Item* item);
	bool drop_inventory();

	void search_inventory();

private:

	Weapon* equiped_weapon;
	bool has_backpack;
	std::vector<Item*> inventory;

};