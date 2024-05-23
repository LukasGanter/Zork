#pragma once
#include "item.h"

class Collectible : public Item
{
public:
	Collectible(const std::string& title, const std::string& description, const ValueTokens token, const std::string& content);
	~Collectible();

	/*
	Prints the story for this collectible to the console
	*/
	void read_story();

protected:

	const std::string& content;
};