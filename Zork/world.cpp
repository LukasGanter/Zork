
#include "world.h"
#include <iostream>
#include "storyline.h"

World::World(std::string title, std::string description) :
    Entity(title, description)
{
}

World::~World()
{
    for (std::vector<Room*>::iterator it = rooms.begin(); it != rooms.end(); ++it)
    {
        delete* it;
    }
    rooms.clear();
}

void World::onPlayerInput(const std::string& input)
{
    std::vector<OrderTokens> order_tokens;
    std::vector<ValueTokens> value_tokens;
    if (Tokenizer::tokenize(input, order_tokens, value_tokens)) {
        for (Room* room : rooms)
        {
            room->updateByToken(order_tokens, value_tokens);
        }
    }
}

void World::tick()
{
    for (Room* room: rooms)
    {
        room->tick();
    }
}

