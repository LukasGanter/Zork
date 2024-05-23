#include "room.h"
#include <iostream>

Room::Room(const std::string& title, const std::string& description, Player* player, const std::vector<Connector*>& connectors, const std::vector<NPC*>& npcs, const std::vector<Item*>& items) :
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

	// For a start only one order token and 0 or 1 value token is used per user input
	const OrderTokens order = order_tokens.empty() ? OrderTokens::UNKNOWN_ORDER : order_tokens[0];
	const ValueTokens value = value_tokens.empty() ? ValueTokens::UNKNOWN_VALUE : value_tokens[0];

	bool took_connector = false;
	int item_index = -1;

	if (player != nullptr) {
		switch (order) {
		case OrderTokens::LOOK:
			// Prints the information about the current room to the screen
			look_around();
			break;
		case OrderTokens::TAKE:
			for (size_t i = 0; i < items.size(); i++) {
				Item* item = items[i];
				Storage* cast_item = static_cast<Storage*>(item);
				if (cast_item->take_item(player, value)) {
					break;
				}
				else {
					if (player->take_item(item)) {
						item_index = i;
					}
				}
			}

			if (item_index != -1) {
				items.erase(items.begin() + item_index);
			}
			else {
				std::cout << "There is not item with that name in this room or any storage containers!\n";
			}
			break;
		case OrderTokens::DROP:
			break;
		case OrderTokens::ATTACK:
			break;
		case OrderTokens::DEFEND:
			break;
		case OrderTokens::TALK:
			break;
		case OrderTokens::EQUIP:
			break;
		case OrderTokens::UNEQUIP:
			break;
		case OrderTokens::LOCK:
			break;
		case OrderTokens::UNLOCK:
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
	items.push_back(item);
}

void Room::look_around()
{
	print_information();
	for (Connector* connector : connectors) {
		connector->print_information();
	}
	for (NPC* npc : npcs) {
		npc->print_information();
	}
	for (Item* item : items) {
		item->print_information();
	}
}
