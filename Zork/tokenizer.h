#pragma once
#include <vector>
#include <string>

enum class OrderTokens
{
	UNKNOWN_ORDER,
	NO_ORDER_INPUT,
	LOOK,
	TAKE,
	LOOT,
	DROP,
	STORE,
	REMEMBER,
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
	NO_VALUE_INPUT,
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
	PASSCODE_TREASURE_CHEST,
	MOUNTAIN_ROOM,
	HUT_ROOM,
	RAVINE_ROOM,
	CAVE_ROOM,
	TREASURE_ROOM
};

/*
Class for converting user input into enum tokens for easier management inside the game structure.
Multiple different user inputs can be converted to the same token.
Currently the case of the letters matter, this is something which would need to be improved in the future
*/
class Tokenizer
{
public:

	/*
	Receives the player input as a string and fills the order and value token lists

	Input "input":			the raw user input
	Input "order_tokens":	result list which contains the orders. Currently only one order per parsing is supported
	Input "value_tokens":	result list which contains the values. Currently only one value per parsing is supported

	Return:					false if the input string was empty, true otherwise
	*/
	static bool tokenize(const std::string& input, std::vector<OrderTokens>& order_tokens, std::vector<ValueTokens>& value_tokens);

private:

	/*
	Uses a switch to parse order tokens from a single user input

	Input "user_token":	the order part of the user raw input

	Result:				a token representing the input
	*/
	static OrderTokens parseOrderToken(const std::string& user_token);

	/*
	Uses a switch to parse value tokens from a single user input

	Input "user_token":	the value part of the user raw input

	Result:				a token representing the input
	*/
	static ValueTokens parseValueToken(const std::string& user_token);
};