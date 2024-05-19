#include "util.h"
#include <cstdarg>

void Util::split_string(const std::string& input, std::vector<std::string>& parts, const char delimiter)
{
	std::string value;
	for (const char i : input)
	{
		if (i == delimiter && value.length() != 0) {
			parts.push_back(value);
			value = "";
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
