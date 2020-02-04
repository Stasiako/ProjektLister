#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cstring>
#include "word.h"


word* base = NULL;


char asciiToLower(char in) //zamienia duze na male litery
{
	if (in <= 'Z' && in >= 'A')
	{
		return in - ('Z' - 'z');
	}
	return in;
}

void readFile(std::string fileName)
{

	std::ifstream file(fileName);
	if (!file) return;

	std::string someString;
	std::string oneLine;
	int lineCounter = 1;

	while (std::getline(file, oneLine)) //czyta linie z pliku
	{
		char* cstr = new char[oneLine.length() + 1];
		strcpy(cstr, oneLine.c_str());
		char* result = strtok(cstr, " ,-.");

		while (result != 0) 
		{
			someString = result;
			std::transform(someString.begin(), someString.end(), someString.begin(), asciiToLower);

			if (base == NULL)
			{
				base = new word();
				base->phrase = someString;
				base->lineList = new line(lineCounter);
			}
			else
			{
				base->addWord(someString, lineCounter);
			}
			result = strtok(NULL, " ,-.");
		}
		lineCounter++;
	}
	file.close();
}

void saveResultToFile(std::string fileName)
{
	std::fstream  outFile;
	outFile.open(fileName, std::fstream::out);

	word* temp = base; //wskazanie na poczatek listy slow
	while (temp != 0) 
	{
		std::string word = temp->phrase;
		line* lineList = temp->lineList;
		outFile << word << " : ";
		while (lineList != 0)
		{
			outFile << lineList->lineNumber << ", ";
			lineList = lineList->next;
		}
		outFile << std::endl;
		temp = temp->nextWord;
	}
	outFile.close();
}

int main(int argc, char* argv[])
{

	if (argc != 5)
	{
		std::cout << "Nalezy podac cztery argumenty. -i <plik_wejsciowy> -o <plik_wyjsciowy>";
		return -1;
	}

	int inputFile = 0;
	int outputFile = 0;
	std::string firstArgument{ argv[1] };
	std::string secondArgument{ argv[3] };

	if (firstArgument == "-i")
		inputFile = 2;
	if (secondArgument == "-i")
		inputFile = 4;
	if (firstArgument == "-o")
		outputFile = 2;
	if (secondArgument == "-o")
		outputFile = 4;

	readFile(argv[inputFile]);

	base->displayAll();

	saveResultToFile(argv[outputFile]);

	base->clear();
	delete (base);

	return 0;
}