#include "replace.h"

void OpenFiles(char const *inputFileName, char const *outputFileName, std::ifstream &inputFile, std::ofstream &outputFile)
{
	inputFile.open(inputFileName, std::ifstream::in);
	outputFile.open(outputFileName, std::ofstream::out);
}

bool IsOpenedFilesCorrect(std::ifstream &inputFile, std::ofstream &outputFile)
{
	if ((!inputFile) || (!outputFile))
	{
		std::cout << "ERROR: Don't opening input or output file." << std::endl;
		return false;
	}
	return true;
}

bool IsCountArgumentsCorrect(int const &argc)
{
	if (argc < COUNT_ARGS)
	{
		std::cout << "ERROR: Not enough arguments for the program. Usage replace. exe [input] [output] [searchstring] [replacestring]" << std::endl;
		return false;
	}
	else if (argc > COUNT_ARGS)
	{
		std::cout << "ERROR: Too many arguments. [input] [output] [searchstring] [replacestring]" << std::endl;
		return false;
	}
	return true;
}

bool IsSearchStringNotEmpty(std::string const &searchString)
{
	if (searchString == "")
	{
		std::cout << "ERROR: The search string is empty." << std::endl;
		return false;
	}
	return true;
}

void ReplaceSubString(std::string &currentString, std::string &searchString, std::string &replaceString, std::ifstream &inputFile, std::ofstream &outputFile)
{
	std::string::size_type pos;
	for (pos = 0; pos != currentString.size();)
	{
		if ((currentString.substr(pos, searchString.size())).compare(searchString) == 0)
		{
			pos += searchString.size();
			outputFile << replaceString;
		}
		else
		{
			outputFile << currentString[pos];
			pos++;
		}
	}
}

void StringReplacing(std::string &searchString, std::string &replaceString, std::ifstream &inputFile, std::ofstream &outputFile)
{
	std::string currentString;	
	while (!inputFile.eof())
	{
		std::getline(inputFile, currentString);
		ReplaceSubString(currentString, searchString, replaceString, inputFile, outputFile);
		outputFile << std::endl;
	}
}

bool CopyFileWithStringReplacing(char *nameInputFile, char *nameOutputFile, std::string &searchString, std::string replaceString)
{
	std::ifstream inputFile;
	std::ofstream outputFile;
	
	OpenFiles(nameInputFile, nameOutputFile, inputFile, outputFile);
	if ((IsSearchStringNotEmpty(searchString)) && (IsOpenedFilesCorrect(inputFile, outputFile)))
	{
		StringReplacing(searchString, replaceString, inputFile, outputFile);
		return true;
	}
	return false;
}

int main(int argc, char *argv[])
{
	if (IsCountArgumentsCorrect(argc))
	{
		return !CopyFileWithStringReplacing(argv[1], argv[2], argv[3], argv[4]);
	}
	return 1;
}