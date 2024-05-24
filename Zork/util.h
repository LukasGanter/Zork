#pragma once
#include <string>
#include <vector>

/*
Utility class
Currently used for string operations
*/
class Util
{
public:
	
	/*
	Splits the given input string using the given delimiter and adds the result to the output list.
	Currently restricted to only splitting at the first occurence of the delimiter in the input string

	Input "input":		the raw user input
	Input "parts":		result list which contains the parts
	Input "delimiter":	the delimiter, standard is space

	*/
	static void split_string(const std::string& input, std::vector<std::string>& parts, const char delimiter = ' ');

	/*
	Compares a string for equality against a list of possible options

	Input "target":		the target string the list is compared against
	Input "values":		the list of strings, from which at least one must equal target in order to return true

	Return:				false if none of the values in the list match the target, true otherwise
	*/
	static bool equals_strings(const std::string& target, std::initializer_list<std::string> values);

};
