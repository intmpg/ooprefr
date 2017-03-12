#include "stdafx.h"
#include "..\task1\HtmlDecode.h"

using namespace std;

bool StringsAreEqual(string const x, string const y)
{
	return x == y;
}

BOOST_AUTO_TEST_SUITE(ProcessVector_function)

	// Создает пустой вектор из пустого вектора
	BOOST_AUTO_TEST_CASE(makes_empty_string_from_empty_string)
	{
		string emptyString;
		StringHtmlDecode(emptyString);
		BOOST_CHECK(emptyString.empty()); 
	}

	BOOST_AUTO_TEST_CASE(processing_a_string_without_word_for_change)
	{
		string line = "&quot &lt";
		string result = StringHtmlDecode(line);
		
		BOOST_CHECK(StringsAreEqual(line, result));
	}

	BOOST_AUTO_TEST_CASE(processing_a_string_with_only_one_word_for_change)
	{
		string line = "&quot &gt;";
		string rightLine = "&quot >";
		string result = StringHtmlDecode(line);
		BOOST_CHECK(StringsAreEqual(rightLine, result));
	}

	BOOST_AUTO_TEST_CASE(processing_a_string_with_more_than_one_word_for_change)
	{
		string line = "&quot; privet &apos; :) &lt; qwerty &gt&amp;";
		string rightLine = "\" privet ' :) < qwerty &gt&";
		string result = StringHtmlDecode(line);
		BOOST_CHECK(StringsAreEqual(rightLine, result));
	}

BOOST_AUTO_TEST_SUITE_END()


