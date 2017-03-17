#include "stdafx.h"
#include "Process.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string s;
	WordOccurrences m;
	while (getline(cin, s))
	{
		AddStringOccurrence(m, s);
	}
	for (auto s : m)
	{
		cout << s.first << " - " << s.second << " times" << endl;
	}
}

