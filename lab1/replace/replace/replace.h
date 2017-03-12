#pragma once
#include <string>
#include <iostream>
#include <fstream>

static const unsigned int COUNT_ARGS = 5;
static const unsigned int MAX_FILE_SIZE_IN_GB = 2;

bool IsCountArgumentsCorrect(int const &argc);
bool CopyFileWithStringReplacing(char *nameInputFile, char *nameOutputFile, std::string const &searchString, std::string replaceString);
void StringReplacing(std::string const &searchString, std::string const &replaceString, std::ifstream &inputFile, std::ofstream &outputFile);
bool IsSearchStringNotEmpty(std::string const &searchString);