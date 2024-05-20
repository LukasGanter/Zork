#pragma once

#include "character.h"

class NPC : public Character
{
public:
	NPC(std::string title, std::string description);
	~NPC();

public:
	void tick() override;

};