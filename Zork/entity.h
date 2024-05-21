#pragma once
#include <string>

class Entity
{
public:
	Entity(const std::string& id, const std::string& title, const std::string& description);
	~Entity();

	const void printInformation();

public:
	const std::string& id;
	const std::string& title;
	const std::string& description;
};