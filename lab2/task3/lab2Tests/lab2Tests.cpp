#include "stdafx.h"
#include "../lab2_task3/Process.h"

using namespace std;

bool MapsAreEqual(const WordOccurrences &a, const WordOccurrences &b)
{
	return (a.size() == b.size()) && equal(a.cbegin(), a.cend(), b.cbegin());
}

WordOccurrences CalculateOccurrences(const string &str)
{
	WordOccurrences result;
	AddStringOccurrence(result, str);
	return result;
}

BOOST_AUTO_TEST_CASE(EmptyString)
{
	string s = "";
	BOOST_CHECK(CalculateOccurrences(s).size() == 0);
}

BOOST_AUTO_TEST_CASE(StringWithOnlyDelimiters)
{
	string s = "\t   \t \n\n\t  \n ";
	BOOST_CHECK(CalculateOccurrences(s).size() == 0);
}

BOOST_AUTO_TEST_CASE(StringWithDifferentWords)
{
	string s = "one two  three\n";
	BOOST_CHECK(MapsAreEqual(CalculateOccurrences(s), { { "one", 1 }, { "two", 1 }, { "three", 1 } }));
}

BOOST_AUTO_TEST_CASE(StringWithSameWords)
{
	string s = "one two  one three three three   \n";
	BOOST_CHECK(MapsAreEqual(CalculateOccurrences(s), { { "one", 2 }, { "two", 1 }, { "three", 3 } }));
}

BOOST_AUTO_TEST_CASE(StringWithOneWord)
{
	string s = "one";
	BOOST_CHECK(MapsAreEqual(CalculateOccurrences(s), { { "one", 1 } }));
}