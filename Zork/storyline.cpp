#include "storyline.h"

Storyline::Storyline(std::vector<std::string> story) : story(story), currentStoryPoint(0) {}

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
	currentStoryPoint = 0;
}
