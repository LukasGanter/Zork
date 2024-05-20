#pragma once
#include <string>

class Entity
{
public:
	Entity(std::string title, std::string description);
	~Entity();

	const void printInformation();

public:
	std::string title;
	std::string description;
};