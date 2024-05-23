#pragma once
#include <vector>
#include <string>

enum class OrderTokens
{
	UNKNOWN_ORDER,
	LOOK,
	TAKE,
	DROP,
	MOVE,
	ATTACK,
	DEFEND,
	TALK,
	READ,
	INVENTORY,
	EQUIP,
	UNEQUIP,
	LOCK,
	UNLOCK
};

enum class ValueTokens
{
	UNKNOWN_VALUE,
	NORTH,
	EAST,
	SOUTH,
	WEST,
	UP,
	DOWN,
	OLD_MAN,
	SMALL_STICK,
	LARGE_STICK,
	KEY_METAL,
	POSTBOX,
	IRON_ROD,
	SWORD_OF_THE_SONS,
	STURDY_SHIELD,
	LETTER_FRAGMENT_MOUNTAINS,
	LETTER_FRAGMENT_HUT,
	LETTER_FRAGMENT_CAVE,
	LETTER_FRAGMENT_RAVINE,
	LETTER_FRAGMENT_TREASURE_ROOM,
	MEDALLION_WISEDOM,
	CHEST_TREASURE,
	PASSCODE_TREASURE_CHEST
};

class Tokenizer
{
public:
	static bool tokenize(const std::string& input, std::vector<OrderTokens>& order_tokens, std::vector<ValueTokens>& value_tokens);

private:

	static OrderTokens parseOrderToken(const std::string& user_token);
	static ValueTokens parseValueToken(const std::string& user_token);
};