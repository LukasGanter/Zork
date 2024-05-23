#include "room.h"
#include <iostream>
#include "chest.h"

Room::Room(const std::string& title, const std::string& description, Player* player, std::initializer_list<Connector*> connectors, std::initializer_list<NPC*> npcs, std::initializer_list<Item*> items) :
	Entity(title, description), player(player), connectors(connectors), npcs(npcs), items(items)
{

}

Room::~Room()
{
	for (std::vector<Connector*>::iterator it = connectors.begin(); it != connectors.end(); ++it)
	{
		delete* it;
	}
	connectors.clear();

	for (std::vector<NPC*>::iterator it = npcs.begin(); it != npcs.end(); ++it)
	{
		delete* it;
	}
	npcs.clear();

	for (std::vector<Item*>::iterator it = items.begin(); it != items.end(); ++it)
	{
		delete* it;
	}
	items.clear();

	delete player;
	player = nullptr;
}

void Room::update_by_token(std::vector<OrderTokens>& order_tokens, std::vector<ValueTokens>& value_tokens)
{
	// Stop any interaction with npcs if the user enters another order
	for (NPC* npc : npcs) {
		npc->stop_talk();
	}

	// For a start only one order token and 0 or 1 value token is used per user input
	const OrderTokens order = order_tokens.empty() ? OrderTokens::NO_ORDER_INPUT : order_tokens[0];
	const ValueTokens value = value_tokens.empty() ? ValueTokens::NO_VALUE_INPUT : value_tokens[0];

	bool took_connector = false;
	int item_index = -1;
	std::vector<Key*> keys;
	NPC* npc;

	if (player != nullptr) {
		switch (order) {
		case OrderTokens::LOOK:
			// Prints the information about the current room to the screen
			look_around();
			break;
		case OrderTokens::LOOT:
			if (!check_wrong_value_input(value)) {
				break;
			}
			for (size_t i = 0; i < items.size(); i++) {
				Item* item = items[i];
				if (static_cast<Storage*>(item) && item->token == value) {
					static_cast<Storage*>(item)->take_item(player);
					break;
				}
			}
			break;
		case OrderTokens::TAKE:
			if (!check_wrong_value_input(value)) {
				break;
			}
			for (size_t i = 0; i < items.size(); i++) {
				Item* item = items[i];
				if (item->token == value) {
					if (player->take_item(item, value)) {
						item_index = i;
						break;
					}
				}
			}

			if (item_index != -1) {
				items.erase(items.begin() + item_index);
			}
			else {
				std::cout << "There is no item with that name in this room!\n";
			}
			break;
		case OrderTokens::DROP:
			if (value == ValueTokens::NO_VALUE_INPUT) {
				player->drop_inventory(this);
			}
			else {
				player->drop_item(this, value);
			}
			break;
		case OrderTokens::STORE:

			break;
		case OrderTokens::ATTACK:

			break;
		case OrderTokens::DEFEND:
			break;
		case OrderTokens::TALK:
			npc = get_npc_for_token(value);
			if (npc != nullptr) {
				npc->talk(player->has_medallion());
			}
			else {
				std::cout << "Nobody with that name is here in the room!\n";
			}
			break;
		case OrderTokens::READ:
			if (!check_wrong_value_input(value)) {
				break;
			}
			player->read(value);
			break;
		case OrderTokens::EQUIP:
			player->equip_weapon(value);
			break;
		case OrderTokens::UNEQUIP:
			player->unequip_weapon(this);
			break;
		case OrderTokens::REMEMBER:
			player->remember_key(value);
			break;
		case OrderTokens::LOCK:
			if (!check_wrong_value_input(value)) {
				break;
			}

			if (player->get_keys_in_inventory(keys)) {
				for (Key* key : keys) {
					for (Connector* connector : connectors) {
						if (connector->exit_direction == value || connector->token == value) {
							connector->lock(key->token);
							return;
						}
					}
					for (Item* item : items) {
						if (static_cast<Chest*>(item) && item->token == value) {
							static_cast<Chest*>(item)->lock(key->token);
							return;
						}
					}
				}
			}
			std::cout << "You do not possess the correct key!\n";
			
			break;
		case OrderTokens::UNLOCK:
			if (!check_wrong_value_input(value)) {
				break;
			}

			if (player->get_keys_in_inventory(keys)) {
				for (Key* key : keys) {
					for (Connector* connector : connectors) {
						if (connector->exit_direction == value) {
							connector->unlock(key->token);
							return;
						}
					}
					for (Item* item : items) {
						if (static_cast<Chest*>(item) && item->token == value) {
							static_cast<Chest*>(item)->unlock(key->token);
							return;
						}
					}
				}
			}
			std::cout << "You do not possess the correct key!\n";

			break;
		case OrderTokens::INVENTORY:
			// Prints the information of all items in the inventory to the screen
			player->search_inventory();
			break;
		case OrderTokens::MOVE: 
			for (Connector* connector : connectors) {
				if (connector->take_connector(value, player)) {
					took_connector = true;
					player = nullptr;
					break;
				}
			}
			if (!took_connector) {
				std::cout << "There is no way in this direction. I can not walk there.\n";
			}
			break;
		default:
			break;
		}
	}
}

void Room::tick()
{
	for (Connector* connector : connectors) {
		connector->tick();
	}
}

void Room::join_room(Player* player)
{
	this->player = player;
	print_information();
}

void Room::drop_item(Item* item)
{
	if (item != nullptr) {
		items.push_back(item);
	}
}

bool Room::check_wrong_value_input(const ValueTokens token)
{
	if (token == ValueTokens::NO_VALUE_INPUT) {
		std::cout << "What object do you want to handle?\n";
		return false;
	}
	else if (token == ValueTokens::UNKNOWN_VALUE) {
		std::cout << "This object does not exist in this world\n";
		return false;
	}
	else {
		return true;
	}
}

NPC* Room::get_npc_for_token(const ValueTokens token)
{
	for (NPC* npc : npcs) {
		if (npc->token == token) {
			return npc;
		}
	}
	return nullptr;
}

Item* Room::get_item_for_token(const ValueTokens token)
{
	for (Item* item : items) {
		if (item->token == token) {
			return item;
		}
	}
	return nullptr;
}

void Room::look_around()
{
	print_information();

	std::cout << "\nAll available ways: \n";

	for (Connector* connector : connectors) {
		connector->print_information();
	}

	std::cout << "\nAll npcs in the area: \n";

	for (NPC* npc : npcs) {
		npc->print_information();
	}

	std::cout << "\nAll items on the floor: \n";

	for (Item* item : items) {
		item->print_information();
	}
}
