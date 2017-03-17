#include "stdafx.h"
#include "Process.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string s;
	vector<string> resultList;
	while (getline(cin, s))
	{
		resultList.push_back(RemoveExtraSpaces(s));
	}
	for (auto curS : resultList)
	{
		cout << curS << endl;
	}
	resultList.clear();
	return 0;
}

