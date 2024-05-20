#pragma once
#include <string>

class Entity
{
public:
	Entity(std::string title, std::string description);
	~Entity();

public:
	std::string title;
	std::string description;
};