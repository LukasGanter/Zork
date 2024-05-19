#pragma once
#include <string>
#include <vector>

class Util
{
public:
	
	static void split_string(const std::string& input, std::vector<std::string>& parts, const char delimiter = ' ');
	static bool equals_strings(const std::string& target, std::initializer_list<std::string> values);

};
