#include "npc.h"

NPC::NPC(const std::string& id, const std::string& title, const std::string& description, const int resistance, const int attack_dmg) :
	Character(id, title, description), resistance(resistance), attack_dmg(attack_dmg)
{
}

NPC::~NPC()
{
}

void NPC::tick()
{
}
