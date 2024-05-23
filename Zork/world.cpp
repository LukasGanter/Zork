

#include "world.h"
#include <iostream>
#include "storyline.h"
#include "stick.h"
#include "key.h"
#include "letterFragment.h"
#include "breakingRod.h"
#include "medaillon.h"
#include "shield.h"
#include "sword.h"

World::World(const std::string& title, const std::string& description) :
    Entity(title, description)
{
    Player* player = new Player("Rantanplan", "Only player in the world");

    Item* mountain_item_1 = new Stick("small", "A small wooden stick", 1, 1, 2, 1);
    Item* mountain_item_2 = new Stick("big", "A big wooden stick", 3, 4, 2, 5);
    Item* mountain_item_3 = new LetterFragment("Fragment3", "A message from the king. ", "5 bandits are travelling the lands. Be aware!");

    Item* hut_item_1 = new BreakingRod("Iron rod", "A large, heavy iron rod designed for destroying obstacles on the way.", 3, 10, 5, 100);
    Item* hut_item_2 = new Sword("Sword of the sons", "A sleek, elegant weapon from ancient times.", 10, 2, 6, 40);
    Item* hut_item_3 = new LetterFragment("Fragment1", "Estate of the great hunter", "Inside the estate there are two of my once greatest possessions.\nThe sword of the sons and the medaillon of the wisedom.");

    // Item* treasure_item_1 = new Chest();
    Item* treasure_item_2 = new Medaillon("Wisedom", "The medaillon of wisedom", "The engraving reads: The medaillon of Wisedom");
    Item* treasure_item_3 = new LetterFragment("Fragment2", "Cursed treasures", "The single treasure in this room is cursed.");

    Item* ravine_item_1 = new LetterFragment("Fragment5", "A planned trap", "Ritsche ratsche voller Tücke in die Brücke eine Lücke!");
    Item* ravine_item_2 = new Shield("Shield", "A sturdy round shield", 1, 1, 10, 80);

    Item* cave_item_1 = new LetterFragment("Fragment4", "A moving stone", "I swear, the big stone in the corner moved.");

    Connector* mountains_connector_1 = new Connector("Door", "The door of the hut", new Storyline({ "The door of the hut" }), ValueTokens::NORTH, true, "Metalkey", 0, 0);
    Connector* mountains_connector_2 = new Connector("Bridge", "The bridge over the ravine", new Storyline({ "You step on the bridge.", "Its more slippery than it looked before", "You fall!", "Darkness surrounds you. Then your vision turns white.", "Hey, you are finally awake!" }),
        ValueTokens::EAST, false, "", 10, 1);

    Connector* hut_connector_1 = new Connector("InnerDoor", "The inside door of the hut", new Storyline({ "The inside door of the hut" }), ValueTokens::SOUTH, false, "Metalkey", 0, 0);

    Connector* ravine_connector_1 = new Connector("CaveEntrance", "A small black hole, leading somewhere into the darkness", new Storyline({ "You knee in front of the hole.",
        "A strong ice cold wind blows from the dark void.", "With a big grown you lay on the ground and rob forwards" }), ValueTokens::WEST, false, "", 0, 0);

    Connector* cave_connector_1 = new Connector("CaveExit", "A small hole with a dim light at the end", new Storyline({ "Like a moth, you are craving for light.", "As fast as possible you rob through the small gap" }),
        ValueTokens::EAST, false, "", 0, 0);
    Connector* cave_connector_2 = new Connector("BoardedHall", "Boarded with heavy wood bars, an exit can be seen in the south part of the cave", new Storyline({ "After hitting the bars for what feels like eternity, you finally break through.", "Before you opens a huge space, empty and illuminated by a mysterious light." }),
        ValueTokens::SOUTH, false, "", 100, 10);
    Connector* cave_connector_3 = new Connector("Skylight", "At the top of the cave there is a perfectly round opening. Climbing to it seems possible.",
        new Storyline({ "You climb the wet and rough rocks of the cave wall", "With your last strength you reach the opening and squeeze yourself in.", "Do you imagine it or does it gets warmer?" }),
        ValueTokens::UP, false, "", 0, 0);

    Connector* treasure_connector_1 = new Connector("TreasureEntrance", "The opened hole with the rest of the wooden planks.", new Storyline({ "You walk back into the cave." }),
        ValueTokens::NORTH, false, "", 0, 0);

    rooms.push_back(new Room("Mountains", "Outside starting area", player, {
        new Connector("Door", "The door of the hut", new Storyline({"The door of the hut"}), ValueTokens::NORTH, true, "Metalkey", 0, 0),
        new Connector("Bridge", "The bridge over the ravine", new Storyline({"You step on the bridge.", "You fall!", "Darkness surrounds you. Then your vision turns white.", "Hey, you are finally awake!"}),
        ValueTokens::EAST, false, "", 10, 1)
        }, {

        }, {
            new Stick("small", "A small wooden stick", 1, 1, 2, 1),
            new Stick("big", "A big wooden stick", 3, 4, 2, 5),
            new LetterFragment("Fragment3", "A message from the king. ", "5 bandits are travelling the lands. Be aware!")
        }));
    rooms.push_back(new Room("Hut", "Hut and an old man", nullptr, {
        new Connector("Door", "The door of the hut", new Storyline({"The door of the hut"}), ValueTokens::NORTH, true, "Metalkey", 0, 0),
        }, {
        }, {
        }));
    rooms.push_back(new Room("Cave", "A narrow, dark and wet passage through the mountain", nullptr, {}, {}, {}));
    rooms.push_back(new Room("Ravine", "A narrow, deep ravine. Like a scar in the landscape. A small suspension bridge spans accross it.", nullptr, 
{
        }, {
            new Key("Metalkey", "A large metal key, suitable for the door of a house", "7") 
        }, {
        }));
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



