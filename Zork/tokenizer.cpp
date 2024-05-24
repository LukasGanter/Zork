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
	if (Util::equals_strings(user_token, { "look", "LOOK"})) {
		return OrderTokens::LOOK;
	}
	else if (Util::equals_strings(user_token, { "loot", "search", "LOOT" })) {
		return OrderTokens::LOOT;
	}
	else if (Util::equals_strings(user_token, { "take", "pick", "aquire", "TAKE" })) {
		return OrderTokens::TAKE;
	}
	else if (Util::equals_strings(user_token, { "drop", "DROP" })) {
		return OrderTokens::DROP;
	}
	else if (Util::equals_strings(user_token, { "remember", "remember key", "REMEMBER" })) {
		return OrderTokens::REMEMBER;
	}
	else if (Util::equals_strings(user_token, { "store", "STORE" })) {
		return OrderTokens::STORE;
	}
	else if (Util::equals_strings(user_token, { "move", "go", "visit", "MOVE" })) {
		return OrderTokens::MOVE;
	}
	else if (Util::equals_strings(user_token, { "attack", "hit", "kill", "ATTACK" })) {
		return OrderTokens::ATTACK;
	}
	else if (Util::equals_strings(user_token, { "defend", "DEFEND" })) {
		return OrderTokens::DEFEND;
	}
	else if (Util::equals_strings(user_token, { "talk", "speak", "greet", "ask", "TALK" })) {
		return OrderTokens::TALK;
	}
	else if (Util::equals_strings(user_token, { "read", "READ" })) {
		return OrderTokens::READ;
	}
	else if (Util::equals_strings(user_token, { "inventory", "overview", "items", "INVENTORY" })) {
		return OrderTokens::INVENTORY;
	}
	else if (Util::equals_strings(user_token, { "equip", "hold", "EQUIP" })) {
		return OrderTokens::EQUIP;
	}
	else if (Util::equals_strings(user_token, { "unequip", "store", "UNEQUIP" })) {
		return OrderTokens::UNEQUIP;
	}
	else if (Util::equals_strings(user_token, { "lock", "close", "LOCK" })) {
		return OrderTokens::LOCK;
	}
	else if (Util::equals_strings(user_token, { "unlock", "open", "UNLOCK" })) {
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
	else if (Util::equals_strings(user_token, { "man", "old man"})) {
		return ValueTokens::OLD_MAN;
	}
	else if (Util::equals_strings(user_token, { "small stick" })) {
		return ValueTokens::SMALL_STICK;
	}
	else if (Util::equals_strings(user_token, { "large stick" })) {
		return ValueTokens::LARGE_STICK;
	}
	else if (Util::equals_strings(user_token, { "key", "metal key"})) {
		return ValueTokens::KEY_METAL;
	}
	else if (Util::equals_strings(user_token, { "box", "postbox", "mailbox"})) {
		return ValueTokens::POSTBOX;
	}
	else if (Util::equals_strings(user_token, { "rod", "iron rod" })) {
		return ValueTokens::IRON_ROD;
	}
	else if (Util::equals_strings(user_token, { "sword", "sword of the sons"})) {
		return ValueTokens::SWORD_OF_THE_SONS;
	}
	else if (Util::equals_strings(user_token, { "shield", "sturdy shield"})) {
		return ValueTokens::STURDY_SHIELD;
	}
	else if (Util::equals_strings(user_token, { "letter mountain" })) {
		return ValueTokens::LETTER_FRAGMENT_MOUNTAINS;
	}
	else if (Util::equals_strings(user_token, { "letter hut" })) {
		return ValueTokens::LETTER_FRAGMENT_HUT;
	}
	else if (Util::equals_strings(user_token, { "letter cave" })) {
		return ValueTokens::LETTER_FRAGMENT_CAVE;
	}
	else if (Util::equals_strings(user_token, { "letter ravine" })) {
		return ValueTokens::LETTER_FRAGMENT_RAVINE;
	}
	else if (Util::equals_strings(user_token, { "letter treasure" })) {
		return ValueTokens::LETTER_FRAGMENT_TREASURE_ROOM;
	}
	else if (Util::equals_strings(user_token, { "medallion", "wisedom"})) {
		return ValueTokens::MEDALLION_WISEDOM;
	}
	else if (Util::equals_strings(user_token, { "treasure chest", "chest" })) {
		return ValueTokens::CHEST_TREASURE;
	}
	else if (Util::equals_strings(user_token, { "21591"})) {
		return ValueTokens::PASSCODE_TREASURE_CHEST;
	}
	else if (Util::equals_strings(user_token, { "Mountains", "mountains" })) {
		return ValueTokens::MOUNTAIN_ROOM;
	}
	else if (Util::equals_strings(user_token, { "Hut", "hut", "door", "Doorsearch mailbox"})) {
		return ValueTokens::HUT_ROOM;
	}
	else if (Util::equals_strings(user_token, { "Ravine", "ravine" })) {
		return ValueTokens::RAVINE_ROOM;
	}
	else if (Util::equals_strings(user_token, { "Cave", "cave"})) {
		return ValueTokens::CAVE_ROOM;
	}
	else if (Util::equals_strings(user_token, { "treasures", "Treasures"})) {
		return ValueTokens::TREASURE_ROOM;
	}

	return ValueTokens::UNKNOWN_VALUE;
}
