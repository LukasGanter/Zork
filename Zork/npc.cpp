#include "npc.h"
#include <iostream>

NPC::NPC(const std::string& title, const std::string& description, const ValueTokens token, const int resistance, const int attack_dmg, Storyline* background_story, Storyline* final_story) :
	Character(title, description), token(token), resistance(resistance), attack_dmg(attack_dmg), background_story(background_story), final_story(final_story), is_talking(false), has_medallion(false)
{
}

NPC::~NPC()
{
	delete background_story;
	background_story = nullptr;

	delete final_story;
	final_story = nullptr;
}

void NPC::tick()
{
	if (is_talking) {
		if (has_medallion) {
			if (final_story->tick()) {
				is_talking = false;
				final_story->reset();
			}
		}
		else {
			if (background_story->tick()) {
				is_talking = false;
				background_story->reset();
			}
		}
	}
}

void NPC::talk(bool has_medallion)
{
	std::cout << "You turn to the " << title << " and greet him friendly. He immediatelly starts to talk.\n";
	if (is_talking) {
		stop_talk();
	}
	this->has_medallion |= has_medallion;	// Once the player has the medallion, the npc should always stay in that state
	is_talking = true;
}

void NPC::stop_talk()
{
	if (is_talking) {
		is_talking = false;
		std::cout << "It is very rude to just interrupt someone during a talk! Please leave my house!\n";
		background_story->reset();
		final_story->reset();
	}
}

