

#include "world.h"
#include <iostream>
#include "storyline.h"
#include "stick.h"
#include "key.h"

World::World(const std::string& title, const std::string& description) :
    Entity(title, description)
{
    Player* player = new Player("Rantanplan", "Only player in the world");

    rooms.push_back(new Room("Mountains", "Outside starting area", player, {
        new Connector("Door", "The door of the hut", new Storyline({"The door of the hut"}), ValueTokens::NORTH, true, "Metalkey", 0, 0),
        new Connector("Bridge", "The bridge over the ravine", new Storyline({"You step on the bridge.", "You fall!", "Darkness surrounds you. Then your vision turns white.", "Hey, you are finally awake!"}),
        ValueTokens::EAST, false, "", 10, 1)
        }, {

        }, {
            new Stick("small", "A small wooden stick", 1, 1, 2, 1),
            new Stick("big", "A big wooden stick", 3, 4, 2, 5),
            new Key("Metalkey", "A large metal key, suitable for the door of a house", "7")
        }));
    rooms.push_back(new Room("Hut", "Hut and an old man", nullptr, {}, {}, {}));
    rooms.push_back(new Room("Cave", "This is outside", nullptr, {}, {}, {}));
    rooms.push_back(new Room("Ravine", "This is outside", nullptr, {}, {}, {}));
    rooms.push_back(new Room("Treasures", "This is where the treasure chest hides", nullptr, {}, {}, {}));
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



