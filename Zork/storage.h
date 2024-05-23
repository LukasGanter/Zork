#pragma once

#include "item.h"

class Storage : public Item
{
public:
	Storage(const std::string& title, const std::string& description, const std::string& content);
	~Storage();

protected:


	// TODO Add parameter to item "is_takable"
};