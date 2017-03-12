#include "stdafx.h"
#include "HtmlDecode.h"
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <vector>
#include <boost/range/algorithm/transform.hpp>
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)
#include <boost/algorithm/string.hpp>

using namespace std;

string ReadLine()
{
	string line;
	getline(std::cin, line);
	return line;
}

string StringHtmlDecode(string const htmlLine)
{
	string result = htmlLine;
	vector<string> wordsForSearching = {"&quot;", "&apos;", "&lt;", "&gt;", "&amp;"};
	vector<string> wordsForChanging = {"\"", "'", "<", ">", "&"};
	for (size_t i = 0; i < 5; i++)
	{
		boost::replace_all(result, wordsForSearching[i], wordsForChanging[i]);
	}

	return result;
}