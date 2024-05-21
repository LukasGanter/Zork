

#include "world.h"
#include <iostream>
#include "storyline.h"

World::World(const std::string& title, const std::string& description) :
    Entity(title, description)
{
    Player* player = new Player("Player1", "Only player in the world");
    Room* room1 = new Room("Mountainous terrain", "This is outside", player, {}, {}, {}, {});
}

World::~World()
{
    for (std::vector<Room*>::iterator it = rooms.begin(); it != rooms.end(); ++it)
    {
        delete* it;
    }
    rooms.clear();
}

void World::on_player_input(const std::string& input)
{
    std::vector<OrderTokens> order_tokens;
    std::vector<ValueTokens> value_tokens;
    if (Tokenizer::tokenize(input, order_tokens, value_tokens)) {
        for (Room* room : rooms)
        {
            room->update_by_token(order_tokens, value_tokens);
        }
    }
}

void World::tick()
{
    for (Room* room : rooms)
    {
        room->tick();
    }
}



