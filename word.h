#include <string>
#include "line.h"

struct word
{
	std::string phrase;
	line* lineList;
	word* nextWord;

	void addWord(std::string phrase, int lineNumber);
	void displayCurrent();
	void displayAll();
	void clear();
	word();
};
