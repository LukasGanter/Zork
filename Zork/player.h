#pragma once

#include "character.h"

class Player : public Character
{
public:
	Player();
	~Player();

public:
	void tick() override;

};