#pragma once

#include <vector>
#include "connector.h"
#include "character.h"
#include "weapon.h"
#include "collectible.h"
#include "tokenizer.h"
#include "npc.h"
#include "player.h"

class Room : public Entity
{
public:
	Room(std::string title, std::string description, Player* player);
	~Room();

public:
	void updateByToken(std::vector<OrderTokens>& order_tokens, std::vector<ValueTokens>& value_tokens);
	void tick();

	void joinRoom(Player* player);

private:

	void lookAround();

public:

	Player* player;

	std::vector<Connector*> connectors;
	std::vector<NPC*> npcs;
	std::vector<Collectible*> collectibles;
	std::vector<Weapon*> weapons;
};
