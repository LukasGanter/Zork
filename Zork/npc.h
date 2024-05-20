#pragma once

#include "character.h"

class NPC : public Character
{
public:
	NPC();
	~NPC();

public:
	void tick() override;

};