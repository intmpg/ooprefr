#include "stdafx.h"
#include "Dictionary.h"

using namespace std;

void CDictionary::StartWorkWithDictionary()
{
	logic.SetFileName();
	ifstream inputFile(logic.GetFileName());
	logic.InputDictionary();
	string wordToTranslate;
	while (wordToTranslate != "...")
	{
		wordToTranslate = GetWordToTranslate();
		if (!HaveTranslate(wordToTranslate) && wordToTranslate != "...")
		{
			cout << "dictionary does not have a given word" << endl << "enter the translation or press enter to skip:";
			string translation = logic.GetTranslation();
			logic.SavingNewWordTranslation(wordToTranslate, translation);
		}
	}

	DialogBeforeFinishWithUser();
}

void CDictionary::DialogBeforeFinishWithUser()
{
	string answer;

	while (answer != "y" && answer != "n")
	{
		cout << "do you want to save dictionary? y/n:";
		getline(cin, answer);
		if (answer == "y")
			logic.SaveDictionaryInFile();
	}
}

string CDictionary::GetWordToTranslate()
{
	string wordToTranslate;
	cout << "input word to translate:";
	getline(cin, wordToTranslate);
	transform(wordToTranslate.begin(), wordToTranslate.end(), wordToTranslate.begin(), tolower);
	return wordToTranslate;
}

bool CDictionary::HaveTranslate(string const & wordToTranslate)
{
	if (logic.HaveRusTranslate(wordToTranslate))
		return true; 
	else 
		return logic.HaveEngTranslate(wordToTranslate);
}


