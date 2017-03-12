// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "HtmlDecode.h"

using namespace std;

int _tmain()
{
	string line = ReadLine();

	string resultLine = StringHtmlDecode(line);

	copy(resultLine.begin(), resultLine.end(), std::ostreambuf_iterator<char>(std::cout));

	return 0;
}

