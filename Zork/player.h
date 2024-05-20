#pragma once

#include "character.h"

class Player : public Character
{
public:
	Player(std::string title, std::string description);
	~Player();

public:
	void tick() override;

};