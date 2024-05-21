#pragma once

#include "character.h"

class NPC : public Character
{
public:
	NPC(const std::string& id, const std::string& title, const std::string& description);
	~NPC();

public:
	void tick() override;

};