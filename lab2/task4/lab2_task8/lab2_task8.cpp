#include "stdafx.h"
#include "Expand.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Not enough arguments" << endl;
		return 0;
	}
	
	ifstream fin(argv[1]);
	if (!fin)
	{
		cout << "Error with opening input file\n" << endl;
		return 1;
	}
	ofstream fout(argv[2]);
	if (!fout)
	{
		cout << "Error with opening output file\n" << endl;
		return 1;
	}

	WordAccordances replaceMap;
	for (int i = 3; i < argc; i += 2)
	{
		string sub = argv[i];
		if (argc <= i + 1)
		{
			cout << "No pair to string " << i - 2 << endl;
			break;
		}
		string rep = argv[i + 1];
		replaceMap[sub] = rep;
	}

	string line;
	while (getline(fin, line))
	{
		fout << ExpandTemplate(line, replaceMap) << endl;
	}

	return 0;
}

