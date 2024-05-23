#pragma once

#include "character.h"
#include "storyline.h"
#include "tokenizer.h"

class NPC : public Character
{
public:
	NPC(const std::string& title, const std::string& description, const ValueTokens token, const int resistance, const int attack_dmg, Storyline* background_story, Storyline* final_story);
	~NPC();

public:
	// World tick
	void tick() override;

	/*
	Initiates the talk sequence of the character

	Input "has_medallion":	Describes which talk will be held. 
	*/
	void talk(bool has_medallion);

	/*
	Stops the talk sequence if the user does something different
	*/
	void stop_talk();

public:

	const ValueTokens token;

	Storyline* background_story;
	Storyline* final_story;

	bool is_talking;
	bool has_medallion;

	const int resistance;
	const int attack_dmg;
};