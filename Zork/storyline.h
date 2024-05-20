#pragma once
#include <string>
#include <vector>

class Storyline
{
public: 
	Storyline(std::vector<std::string> story);

	bool getNextLine(std::string& nextLine);

	void reset();

private:

	std::vector<std::string> story;
	int currentStoryPoint;
};