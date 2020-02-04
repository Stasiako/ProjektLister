#include "word.h"
#include <iostream>

word::word() 
{
	lineList = 0;
	nextWord = 0;
}

void word::addWord(std::string phrase, int lineNumber)
{
	int comparison = this->phrase.compare(phrase);

	if (comparison == 0)
	{
		line* temp = this->lineList;
		while (temp->next != 0)
		{
			temp = temp->next;
		}
		temp->next = new line(lineNumber);
	}
	else if (comparison < 0) 
	{
		word* newWord = new word();
		newWord->phrase = phrase;
		newWord->lineList = new line(lineNumber);

		if (nextWord == 0)
		{
			nextWord = newWord;
		}
		else
		{
			nextWord->addWord(phrase, lineNumber);
		}
	}
	else 
	{
		word* newWord = new word();
		newWord->phrase = this->phrase;
		newWord->lineList = this->lineList;
		newWord->nextWord = this->nextWord;
		
		this->phrase = phrase;
		this->lineList = new line(lineNumber);
		this->nextWord = newWord;
	}

}

void word::displayCurrent()
{
	std::cout << phrase << ": ";
	line* temp = lineList;
	while (temp != 0) 
	{
		std::cout << temp->lineNumber << ", ";
		temp = temp->next;
	}
}

void word::displayAll() 
{
	this->displayCurrent();
	if (this->nextWord != 0)
	{
		this->nextWord->displayAll();
	}
}

void word::clear() 
{
	if (this->nextWord != 0) {
		this->nextWord->clear();
	}
	delete(this->nextWord);
	this->lineList->clear();
	delete(this->lineList);
}
