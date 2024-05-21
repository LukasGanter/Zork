#pragma once

#include "character.h"

class NPC : public Character
{
public:
	NPC(const std::string& id, const std::string& title, const std::string& description, const int resistance, const int attack_dmg);
	~NPC();

public:
	void tick() override;

public:

	const int resistance;
	const int attack_dmg;
};