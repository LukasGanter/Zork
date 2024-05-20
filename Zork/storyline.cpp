#include "storyline.h"
#include <iostream>

Storyline::Storyline(std::vector<std::string> story) : story(story), currentStoryPoint(0), counter(0), ticksBetweenStoryParts(5)
{
	
}

bool Storyline::tick()
{
	bool story_finished = false;
	if (counter >= ticksBetweenStoryParts) {
		std::string next_part;
		story_finished = getNextLine(next_part);
		std::cout << next_part << "\n";

		counter = 0;
		return story_finished;
	}
	else {
		counter++;
		story_finished = false;
	}
	return story_finished;
}

bool Storyline::getNextLine(std::string& nextLine)
{

	if (currentStoryPoint >= story.size()) {
		currentStoryPoint = 0;
		return false;
	}
	else {
		nextLine = story[currentStoryPoint];
		currentStoryPoint++;
		return true;
	}
}

void Storyline::reset()
{
	counter = 0;
	currentStoryPoint = 0;
}
