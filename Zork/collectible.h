#pragma once
#include "item.h"

class Collectible : public Item
{
public:
	Collectible(const std::string& title, const std::string& description, const std::string& story);
	~Collectible();

	/*
	Prints the story for this collectible to the console
	*/
	void read_story();

protected:

	const std::string& story;
};