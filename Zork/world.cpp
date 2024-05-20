
#include "world.h"
#include <iostream>

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

void World::tick()
{
    for (Room* room: rooms)
    {
        room->tick();
    }
}