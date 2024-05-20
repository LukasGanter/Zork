#pragma once
#include <string>
#include <vector>

class Storyline
{
public: 
	Storyline(std::vector<std::string> story);

	bool tick();

	void reset();

private:

	bool getNextLine(std::string& nextLine);

private:

	int counter;
	int ticksBetweenStoryParts;
	std::vector<std::string> story;

	int currentStoryPoint;
};