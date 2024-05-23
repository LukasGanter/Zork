

#include "world.h"
#include <iostream>
#include "storyline.h"
#include "stick.h"
#include "key.h"
#include "letterFragment.h"
#include "breakingRod.h"
#include "medallion.h"
#include "shield.h"
#include "sword.h"
#include "character.h"
#include "chest.h"

World::World(const std::string& title, const std::string& description) :
    Entity(title, description)
{
    Player* player = new Player("Rantanplan", "Only player in the world");

    Item* mountain_item_1 = new Stick("small stick", "A small wooden stick", ValueTokens::SMALL_STICK, 1, 1, 2, 1);
    Item* mountain_item_2 = new Stick("large stick", "A big wooden stick", ValueTokens::LARGE_STICK, 3, 4, 2, 5);
    Item* mountain_item_3 = new LetterFragment("letter mountain", "A message from the king.\n5 bandits are travelling the lands.Be aware!", ValueTokens::LETTER_FRAGMENT_MOUNTAINS);
    Item* mountain_item_4 = new Key("metal key", "A large metal key, suitable for the door of a house", ValueTokens::KEY_METAL);
    Item* mountain_item_5 = new Chest("postbox", "A small wooden box in the middle of the field, adjacent to the house", ValueTokens::POSTBOX, mountain_item_4, false, ValueTokens::UNKNOWN_VALUE);

    Item* hut_item_1 = new BreakingRod("iron rod", "A large, heavy iron rod designed for destroying obstacles on the way.", ValueTokens::IRON_ROD, 3, 10, 5, 100);
    Item* hut_item_2 = new Sword("sword of the sons", "A sleek, elegant weapon from ancient times.", ValueTokens::SWORD_OF_THE_SONS, 10, 2, 6, 40);
    Item* hut_item_3 = new LetterFragment("letter hut", "Estate of the great hunter\nInside the estate there are two of my once greatest possessions.\nThe sword of the sons and the medaillon of the wisedom.",
        ValueTokens::LETTER_FRAGMENT_HUT);

    Item* treasure_item_1 = new Medallion("medallion", "The engraving reads: The medallion of wisedom", ValueTokens::MEDALLION_WISEDOM);
    Item* treasure_item_2 = new LetterFragment("letter treasure", "Cursed treasures.\nThe single treasure in this room is cursed.", ValueTokens::LETTER_FRAGMENT_TREASURE_ROOM);
    Item* treasure_item_3 = new Chest("treasure chest", "A large wooden chest with golden metal framings. Must contain valuable things!", ValueTokens::CHEST_TREASURE, treasure_item_1, true, ValueTokens::PASSCODE_TREASURE_CHEST);

    Item* ravine_item_1 = new LetterFragment("letter ravine", "A planned trap.\nA suspension bridge with one loose board.", ValueTokens::LETTER_FRAGMENT_RAVINE);
    Item* ravine_item_2 = new Shield("sturdy shield", "A sturdy round shield", ValueTokens::STURDY_SHIELD, 1, 1, 10, 80);

    Item* cave_item_1 = new LetterFragment("letter cave", "So dark that the light of the torch does not reach the far sides.\nI swear, the big stone in the corner moved. 9 times!", ValueTokens::LETTER_FRAGMENT_CAVE);

    Connector* mountains_connector_1 = new Connector("Door", "The north door of the hut", ValueTokens::HUT_ROOM, new Storyline({ "The door of the hut" }), ValueTokens::NORTH, true, ValueTokens::KEY_METAL, 0, 0);
    Connector* mountains_connector_2 = new Connector("Bridge", "The east bridge over the ravine", ValueTokens::RAVINE_ROOM, new Storyline({ "You step on the bridge.", "Its more slippery than it looked before", "You fall!", "Darkness surrounds you. Then your vision turns white.", "Hey, you are finally awake!" }),
        ValueTokens::EAST, false, ValueTokens::UNKNOWN_VALUE, 0, 0);

    Connector* hut_connector_1 = new Connector("Mountains", "The door to the ouside mountains area in the south", ValueTokens::MOUNTAIN_ROOM, 
        new Storyline({ "You step through the door into blinding lights" }), ValueTokens::SOUTH, false, ValueTokens::KEY_METAL, 0, 0);

    Connector* ravine_connector_1 = new Connector("Cave", "A small black hole in the west, leading somewhere into the darkness", ValueTokens::CAVE_ROOM, new Storyline({ "You knee in front of the hole.",
        "A strong ice cold wind blows from the dark void.", "With a big grown you lay on the ground and rob forwards" }), ValueTokens::WEST, false, ValueTokens::UNKNOWN_VALUE, 0, 0);

    Connector* cave_connector_1 = new Connector("Ravine", "A small hole in the east with a dim light at the end", ValueTokens::RAVINE_ROOM, new Storyline({ "Like a moth, you are craving for light.", "As fast as possible you rob through the small gap" }),
        ValueTokens::EAST, false, ValueTokens::UNKNOWN_VALUE, 0, 0);
    Connector* cave_connector_2 = new Connector("Treasures", "Boarded with heavy wood bars, an exit can be seen in the south part of the cave", ValueTokens::TREASURE_ROOM
        , new Storyline({ "After hitting the bars for what feels like eternity, you finally break through.", "Before you opens a huge space, empty and illuminated by a mysterious light." }),
        ValueTokens::SOUTH, false, ValueTokens::UNKNOWN_VALUE, 0, 0);
    Connector* cave_connector_3 = new Connector("Mountains", "At the top of the cave there is a perfectly round opening. Climbing to it seems possible.", ValueTokens::MOUNTAIN_ROOM,
        new Storyline({ "You climb the wet and rough rocks of the cave wall", "With your last strength you reach the opening and squeeze yourself in.", "Do you imagine it or does it gets warmer?" }),
        ValueTokens::UP, false, ValueTokens::UNKNOWN_VALUE, 0, 0);

    Connector* treasure_connector_1 = new Connector("Cave", "The opened hole in the north with the rest of the wooden planks.", ValueTokens::CAVE_ROOM, new Storyline({ "You walk back into the cave." }),
        ValueTokens::NORTH, false, ValueTokens::UNKNOWN_VALUE, 0, 0);

    NPC* hut_man = new NPC("Man", "An old man living in a remote mountain hut", ValueTokens::OLD_MAN, 2, 1, 
        new Storyline({
            "Hello, what leads you out here into the wilderness?", "Hello, i am one a far journey across the country.\nHow long have you been living here ouside all by yourself?", 
            "I have been living here for ages. My father told me about a precious medallion which should be buried here somewhere.\nHowever i did not find it ever. I have given up hope.", 
            "I will keep my eyes open. See you soon.", "It was nice to meet you, have a save trip."
            }), 
        new Storyline({"Oh, you are back. Do you have the medallion?", "Yes, i have it here. It was stored away in a chest in the cave adjacent to the ravine.", 
            "Wow, it look exactly like i remember it. I can not thank you enought."}));

    // Mountain room
    Room* room_mountain = new Room("Mountains", "A far and open landscape.", player,
        { mountains_connector_1, mountains_connector_2 },
        {},
        { mountain_item_1, mountain_item_2, mountain_item_3, mountain_item_5 });

    // Hut room
    Room* room_hut = new Room("Hut", "A small house, completely isolated. Home of the old man", nullptr,
        { hut_connector_1 },
        { hut_man },
        { hut_item_1, hut_item_2, hut_item_3 });

    // Ravine room
    Room* room_ravine = new Room("Ravine", "A narrow, deep ravine. Like a scar in the landscape. A small suspension bridge spans accross it.", nullptr,
        { ravine_connector_1 },
        {  },
        { ravine_item_1, ravine_item_2 });

    // Cave room
    Room* room_cave = new Room("Cave", "A narrow, dark and wet passage through the mountain", nullptr,
        { cave_connector_1, cave_connector_2, cave_connector_3 },
        {  },
        { cave_item_1 });

    // Treasure room
    Room* room_treasure = new Room("Treasures", "This is where the treasure chest hides", nullptr,
        { treasure_connector_1 },
        {  },
        { treasure_item_2, treasure_item_3 });

    mountains_connector_1->init_target(room_hut);
    mountains_connector_2->init_target(room_ravine);

    hut_connector_1->init_target(room_mountain);

    ravine_connector_1->init_target(room_cave);

    cave_connector_1->init_target(room_ravine);
    cave_connector_2->init_target(room_treasure);
    cave_connector_3->init_target(room_mountain);

    treasure_connector_1->init_target(room_cave);

    rooms.push_back(room_mountain);
    rooms.push_back(room_hut);
    rooms.push_back(room_ravine);
    rooms.push_back(room_cave);
    rooms.push_back(room_treasure);
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



