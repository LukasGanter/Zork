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
	Room(const std::string& id, const std::string& title, const std::string& description, Player* player, const std::vector<Connector*>& connectors, const std::vector<NPC*>& npcs, const std::vector<Collectible*>& collectibles, const std::vector<Weapon*>& weapons);
	~Room();

public:
	void update_by_token(std::vector<OrderTokens>& order_tokens, std::vector<ValueTokens>& value_tokens);
	void tick();

	void join_room(Player* player);

private:

	void look_around();

public:

	Player* player;

	std::vector<Connector*> connectors;
	std::vector<NPC*> npcs;
	std::vector<Collectible*> collectibles;
	std::vector<Weapon*> weapons;
};

