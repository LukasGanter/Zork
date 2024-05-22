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
	GOLEM,
	LEOPARD,
	FATHER,
	STICK,
	BACKPACK,
	SWORD,
	SHIELD,
	LETTER_FRAGMENT_CAVE,
	LETTER_FRAGMENT_HOUSE,
	LETTER_FRAGMENT_PIT,
	LETTER_FRAGMENT_MOUNTAINS,
	LETTER_FRAGMENT_RIVER,
	KEY,
	BREAKING_ROD,
	TREASURE_CHEST,
	MEDAILLON
};

class Tokenizer
{
public:
	static bool tokenize(const std::string& input, std::vector<OrderTokens>& order_tokens, std::vector<ValueTokens>& value_tokens);

private:

	static OrderTokens parseOrderToken(const std::string& user_token);
	static ValueTokens parseValueToken(const std::string& user_token);
};