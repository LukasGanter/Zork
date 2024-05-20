#include "room.h"
#include <iostream>

Room::Room(std::string title, std::string description, Player* player) :
	Entity(title, description), player(player)
{
}

Room::~Room()
{
}

void Room::updateByToken(std::vector<OrderTokens>& order_tokens, std::vector<ValueTokens>& value_tokens)
{
	// For a start only one order token and 0 or 1 value token is used per user input
	const OrderTokens order = order_tokens.size() > 0 ? order_tokens[0] : OrderTokens::UNKNOWN_ORDER;
	const ValueTokens value = value_tokens.size() > 0 ? value_tokens[0] : ValueTokens::UNKNOWN_VALUE;

	if (player != nullptr) {
		switch (order) {
		case OrderTokens::LOOK:
			lookAround();
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
			bool took_connector;
			for (Connector* connector : connectors) {
				if (connector->takeConnector(value, player)) {
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

void Room::joinRoom(Player* player)
{
	this->player = player;
	printInformation();
}

void Room::lookAround()
{
	printInformation();
}
