#include "tokenizer.h"
#include "util.h"
#include <iostream>

bool Tokenizer::tokenize(const std::string& input, std::vector<OrderTokens>& order_tokens, std::vector<ValueTokens>& value_tokens)
{
	std::vector<std::string> input_parts;

	Util::split_string(input, input_parts);

	if (input_parts.empty()) {
		return false;
	}

	order_tokens.push_back(parseOrderToken(input_parts[0]));

	for(size_t i = 1; i < input_parts.size(); i++) {
		value_tokens.push_back(parseValueToken(input_parts[i]));
	}

	return true;
}

OrderTokens Tokenizer::parseOrderToken(const std::string& user_token)
{
	if (Util::equals_strings(user_token, { "look" })) {
		return OrderTokens::LOOK;
	}
	else if (Util::equals_strings(user_token, { "take", "pick", "aquire" })) {
		return OrderTokens::TAKE;
	}
	else if (Util::equals_strings(user_token, { "drop" })) {
		return OrderTokens::DROP;
	}
	else if (Util::equals_strings(user_token, { "move", "go", "visit" })) {
		return OrderTokens::MOVE;
	}
	else if (Util::equals_strings(user_token, { "attack", "hit", "kill" })) {
		return OrderTokens::ATTACK;
	}
	else if (Util::equals_strings(user_token, { "defend" })) {
		return OrderTokens::DEFEND;
	}
	else if (Util::equals_strings(user_token, { "talk", "speak", "greet", "ask"})) {
		return OrderTokens::TALK;
	}
	else if (Util::equals_strings(user_token, { "read" })) {
		return OrderTokens::READ;
	}
	else if (Util::equals_strings(user_token, { "inventory", "overview", "items" })) {
		return OrderTokens::INVENTORY;
	}
	else if (Util::equals_strings(user_token, { "equip", "hold" })) {
		return OrderTokens::EQUIP;
	}
	else if (Util::equals_strings(user_token, { "unequip", "store" })) {
		return OrderTokens::UNEQUIP;
	}
	else if (Util::equals_strings(user_token, { "lock", "close" })) {
		return OrderTokens::LOCK;
	}
	else if (Util::equals_strings(user_token, { "unlock", "open" })) {
		return OrderTokens::UNLOCK;
	}

	return OrderTokens::UNKNOWN_ORDER;
}

ValueTokens Tokenizer::parseValueToken(const std::string& user_token)
{
	if (Util::equals_strings(user_token, { "north", "n" })) {
		return ValueTokens::NORTH;
	}
	else if (Util::equals_strings(user_token, { "east", "e" })) {
		return ValueTokens::EAST;
	}
	else if (Util::equals_strings(user_token, { "south", "s" })) {
		return ValueTokens::SOUTH;
	}
	else if (Util::equals_strings(user_token, { "west", "w" })) {
		return ValueTokens::WEST;
	}
	else if (Util::equals_strings(user_token, { "up" })) {
		return ValueTokens::UP;
	}
	else if (Util::equals_strings(user_token, { "down" })) {
		return ValueTokens::DOWN;
	}
	else if (Util::equals_strings(user_token, { "golem" })) {
		return ValueTokens::GOLEM;
	}
	else if (Util::equals_strings(user_token, { "leopard" })) {
		return ValueTokens::LEOPARD;
	}
	else if (Util::equals_strings(user_token, { "father" })) {
		return ValueTokens::FATHER;
	}
	else if (Util::equals_strings(user_token, { "stick", "branch"})) {
		return ValueTokens::STICK;
	}
	else if (Util::equals_strings(user_token, { "backpack" })) {
		return ValueTokens::BACKPACK;
	}
	else if (Util::equals_strings(user_token, { "sword", "weapon" })) {
		return ValueTokens::SWORD;
	}
	else if (Util::equals_strings(user_token, { "shield" })) {
		return ValueTokens::SHIELD;
	}
	else if (Util::equals_strings(user_token, { "letter_cave"})) {
		return ValueTokens::LETTER_FRAGMENT_CAVE;
	}
	else if (Util::equals_strings(user_token, { "letter_house" })) {
		return ValueTokens::LETTER_FRAGMENT_HOUSE;
	}
	else if (Util::equals_strings(user_token, { "letter_pit" })) {
		return ValueTokens::LETTER_FRAGMENT_PIT;
	}
	else if (Util::equals_strings(user_token, { "letter_mountains" })) {
		return ValueTokens::LETTER_FRAGMENT_MOUNTAINS;
	}
	else if (Util::equals_strings(user_token, { "unlock", "open" })) {
		return ValueTokens::LETTER_FRAGMENT_RIVER;
	}
	else if (Util::equals_strings(user_token, { "house_key" })) {
		return ValueTokens::KEY;
	}
	else if (Util::equals_strings(user_token, { "breaking_rod", "rod"})) {
		return ValueTokens::BREAKING_ROD;
	}
	else if (Util::equals_strings(user_token, { "chest" })) {
		return ValueTokens::TREASURE_CHEST;
	}
	else if (Util::equals_strings(user_token, { "medaillon", "treasure"})) {
		return ValueTokens::MEDAILLON;
	}

	return ValueTokens::UNKNOWN_VALUE;
}
