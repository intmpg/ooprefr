#include "stdafx.h"
#include "Process.h"

using namespace std;

void AddStringOccurrence(WordOccurrences &occurrences, const string &s)
{
	string word = "";
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		{
			if (word.length() > 0)
			{
				occurrences[word]++;
			}
			word = "";
			continue;
		}
		word += s[i];
	}
	if (word.length() > 0)
	{
		occurrences[word]++;
	}
}