#pragma once
#include <string>
#include <vector>

/*
Class which manages a story. This is a list of text elements which get printed out over an extended amout of time.
Used for conversations and changes between rooms.
*/
class Storyline
{
public: 
	Storyline(const std::vector<std::string>& story);

	/*
	Story tick, only called while the story is active
	Manages timing of the printing of the text elements

	Return:		Whether the story finished during this tick
	*/
	bool tick();

	// Resets the story. Next tick call will start the story from the start
	void reset();

private:

	/*
	Prints the next line to the console

	Input "next_line":	output reference for the next story line

	Return:				Whether the story has finished
	*/
	bool getNextLine(std::string& next_line);

private:

	int counter;
	int ticksBetweenStoryParts;
	const std::vector<std::string> story;

	size_t currentStoryPoint;
};