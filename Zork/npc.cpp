#include "npc.h"

NPC::NPC(const std::string& id, const std::string& title, const std::string& description) :
	Character(id, title, description)
{
}

NPC::~NPC()
{
}

void NPC::tick()
{
}
