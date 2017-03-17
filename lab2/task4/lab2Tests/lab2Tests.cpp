#include "stdafx.h"
#include "../lab2_task8/Expand.h"

using namespace std;

BOOST_AUTO_TEST_CASE(EmptyString)
{
	const string tpl = "";
	WordAccordances params;
	BOOST_CHECK_EQUAL(ExpandTemplate(tpl, params), "");
}

BOOST_AUTO_TEST_CASE(EmptyParams)
{
	const string tpl = "Hello, %USER_NAME%. Today is {WEEK_DAY}.";
	WordAccordances params;
	BOOST_CHECK_EQUAL(ExpandTemplate(tpl, params), "Hello, %USER_NAME%. Today is {WEEK_DAY}.");
}

BOOST_AUTO_TEST_CASE(NoSuchParams)
{
	const string tpl = "Hello, %USER_NAME%. Today is {WEEK_DAY}.";
	WordAccordances params;
	params["One"] = "two";
	params["QQQ"] = "WWW";
	BOOST_CHECK_EQUAL(ExpandTemplate(tpl, params), "Hello, %USER_NAME%. Today is {WEEK_DAY}.");
}

BOOST_AUTO_TEST_CASE(SimpleTemplate)
{
	const string tpl = "Hello, %USER_NAME%. Today is {WEEK_DAY}.";
	WordAccordances params;
	params["%USER_NAME%"] = "Ivan Petrov";
	params["{WEEK_DAY}"] = "Friday";
	BOOST_CHECK_EQUAL(ExpandTemplate(tpl, params), "Hello, Ivan Petrov. Today is Friday.");
}

BOOST_AUTO_TEST_CASE(TemplateWithCoverage)
{
	const string tpl = "Hello, %USER_NAME%. Today is {WEEK_DAY}.";
	WordAccordances params;
	params["%USER_NAME%"] = "Super %USER_NAME% {WEEK_DAY}";
	params["{WEEK_DAY}"] = "Friday. {WEEK_DAY}";
	BOOST_CHECK_EQUAL(ExpandTemplate(tpl, params), "Hello, Super %USER_NAME% {WEEK_DAY}. Today is Friday. {WEEK_DAY}.");
}

BOOST_AUTO_TEST_CASE(TemplateWithMultipleChoice)
{
	const string tpl = "-AABBCCCCCABC+";
	WordAccordances params;
	params["A"] = "[a]";
	params["AA"] = "[aa]";
	params["B"] = "[b]";
	params["BB"] = "[bb]";
	params["C"] = "[c]";
	params["CC"] = "[cc]";
	BOOST_CHECK_EQUAL(ExpandTemplate(tpl, params), "-[aa][bb][cc][cc][c][a][b][c]+");
}

BOOST_AUTO_TEST_CASE(Template)
{
	const string tpl = "{}{}{}{{}}";
	WordAccordances params;
	params["{}"] = "[";
	params["}"] = "]";
	BOOST_CHECK_EQUAL(ExpandTemplate(tpl, params), "[[[{[]");
}