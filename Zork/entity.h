#pragma once
#include <string>

class Entity
{
public:
	Entity(const std::string& title, const std::string& description);
	~Entity();

	/*
	Prints the title and description of this entity to the console
	*/
	const void print_information();

public:
	const std::string title;
	const std::string description;
};