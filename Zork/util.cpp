#include "util.h"
#include <cstdarg>

void Util::split_string(const std::string& input, std::vector<std::string>& parts, const char delimiter)
{
	std::string value;
	bool only_one_split = false;	// Current game version supports one order token and one value token (this token can contain the delimiter)
	for (const char i : input)
	{
		if (!only_one_split && i == delimiter && value.length() != 0) {
			parts.push_back(value);
			value = "";
			only_one_split = true;
		}
		else {
			value += i;
		}
	}
	if (value.length() != 0) {
		parts.push_back(value);
	}
}

bool Util::equals_strings(const std::string& target, std::initializer_list<std::string> values)
{
	bool isEqual = false;

	for (const std::string& value: values) {
		isEqual |= target.compare(value) == 0;
	}

	return isEqual;
}
