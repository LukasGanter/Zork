#include "room.h"
#include <iostream>

Room::Room(const std::string& id, const std::string& title, const std::string& description, Player* player, const std::vector<Connector*>& connectors, const std::vector<NPC*>& npcs, const std::vector<Item*>& items) :
	Entity(id, title, description), player(player), connectors(connectors), npcs(npcs), items(items)
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
	const OrderTokens order = order_tokens.size() > 0 ? order_tokens[0] : OrderTokens::UNKNOWN_ORDER;
	const ValueTokens value = value_tokens.size() > 0 ? value_tokens[0] : ValueTokens::UNKNOWN_VALUE;

	bool took_connector = false;

	if (player != nullptr) {
		switch (order) {
		case OrderTokens::LOOK:
			look_around();
			break;
		case OrderTokens::TAKE:
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
	printInformation();
}

void Room::drop_item(Item* item)
{
	items.push_back(item);
}

void Room::look_around()
{
	printInformation();
}
