#pragma once

#include "connector.h"
#include <vector>
#include "character.h"
#include "weapon.h"
#include "collectible.h"

class Room : public Entity
{
public:
	Room(std::string title, std::string description);
	~Room();

public:
	void tick();

public:

	//std::vector<Connector> connectors;
	//std::vector<Character> characters;
	//std::vector<Collectible> collectibles;
	//std::vector<Weapon> weapons;
};
